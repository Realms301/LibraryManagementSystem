#include <iostream>
#include <string>
using namespace std;

/* =========================
        BOOK CLASS
========================= */
class Book
{
public:
    int bookID;
    string title;
    string author;
    bool isAvailable;

    Book() // default constructor for array initialization
    {
        bookID = 0;
        title = "";
        author = "";
        isAvailable = true;
    }

    Book(int id, string t, string a)
    {
        bookID = id;
        title = t;
        author = a;
        isAvailable = true;
    }

    void displayBook()
    {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

/* =========================
        USER CLASS
========================= */
class User
{
public:
    int userID;
    string name;

    User() // default constructor
    {
        userID = 0;
        name = "";
    }

    User(int ID, string n)
    {
        userID = ID;
        name = n;
    }

    void displayUser()
    {
        cout << "UserID: " << userID << endl;
        cout << "Name: " << name << endl;
    }
};

/* =========================
       LIBRARY CLASS
========================= */
class Library
{
public:
    Book books[100];
    int bookCount = 0;

    User users[100];
    int userCount = 0;

    // --------- BOOK FUNCTIONS ---------
    void addBook(Book b)
    {
        books[bookCount] = b;
        bookCount++;
        cout << "Book added successfully.\n";
    }

    void removeBook(int bookID)
    {
        for(int i = 0; i < bookCount; i++)
        {
            if(books[i].bookID == bookID)
            {
                // shift all books down
                for(int j = i; j < bookCount - 1; j++)
                    books[j] = books[j+1];
                bookCount--;
                cout << "Book removed successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void showBooks()
    {
        cout << "\n--- Library Books ---\n";
        for(int i = 0; i < bookCount; i++)
        {
            books[i].displayBook();
            cout << endl;
        }
    }

    void searchBookByTitle(string t)
    {
        bool found = false;
        for(int i = 0; i < bookCount; i++)
        {
            if(books[i].title == t)
            {
                books[i].displayBook();
                found = true;
            }
        }
        if(!found) cout << "No book found with title \"" << t << "\"\n";
    }

    void searchBookByAuthor(string a)
    {
        bool found = false;
        for(int i = 0; i < bookCount; i++)
        {
            if(books[i].author == a)
            {
                books[i].displayBook();
                found = true;
            }
        }
        if(!found) cout << "No book found by author \"" << a << "\"\n";
    }

    // --------- USER FUNCTIONS ---------
    void addUser(User u)
    {
        users[userCount] = u;
        userCount++;
        cout << "User added successfully.\n";
    }

    void removeUser(int userID)
    {
        for(int i = 0; i < userCount; i++)
        {
            if(users[i].userID == userID)
            {
                for(int j = i; j < userCount - 1; j++)
                    users[j] = users[j+1];
                userCount--;
                cout << "User removed successfully.\n";
                return;
            }
        }
        cout << "User not found.\n";
    }

    void showUsers()
    {
        cout << "\n--- Registered Users ---\n";
        for(int i = 0; i < userCount; i++)
        {
            users[i].displayUser();
            cout << endl;
        }
    }

    // --------- BORROW / RETURN ---------
    void borrowBook(int bookID)
    {
        for(int i = 0; i < bookCount; i++)
        {
            if(books[i].bookID == bookID)
            {
                if(books[i].isAvailable)
                {
                    books[i].isAvailable = false;
                    cout << "Book \"" << books[i].title << "\" borrowed successfully.\n";
                    return;
                }
                else
                {
                    cout << "Book \"" << books[i].title << "\" is already borrowed.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int bookID)
    {
        for(int i = 0; i < bookCount; i++)
        {
            if(books[i].bookID == bookID)
            {
                if(!books[i].isAvailable)
                {
                    books[i].isAvailable = true;
                    cout << "Book \"" << books[i].title << "\" returned successfully.\n";
                    return;
                }
                else
                {
                    cout << "Book \"" << books[i].title << "\" was not borrowed.\n";
                    return;
                }
            }
        }
        cout << "Book not found.\n";
    }
};

/* =========================
           MAIN
========================= */
int main()
{
    Library lib;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add User\n";
        cout << "2. Remove User\n";
        cout << "3. Show Users\n";
        cout << "4. Add Book\n";
        cout << "5. Remove Book\n";
        cout << "6. Show Books\n";
        cout << "7. Search Book by Title\n";
        cout << "8. Search Book by Author\n";
        cout << "9. Borrow Book\n";
        cout << "10. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore(); // clear newline

        if(choice == 1)
        {
            int id;
            string name;
            cout << "Enter User ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin,name);
            lib.addUser(User(id, name));
        }
        else if(choice == 2)
        {
            int id;
            cout << "Enter User ID to remove: ";
            cin >> id;
            lib.removeUser(id);
        }
        else if(choice == 3)
        {
            lib.showUsers();
        }
        else if(choice == 4)
        {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            lib.addBook(Book(id, title, author));
        }
        else if(choice == 5)
        {
            int id;
            cout << "Enter Book ID to remove: ";
            cin >> id;
            lib.removeBook(id);
        }
        else if(choice == 6)
        {
            lib.showBooks();
        }
        else if(choice == 7)
        {
            string title;
            cout << "Enter Book Title to search: ";
            cin.ignore();
            getline(cin, title);
            lib.searchBookByTitle(title);
        }
        else if(choice == 8)
        {
            string author;
            cout << "Enter Author Name to search: ";
            cin.ignore();
            getline(cin, author);
            lib.searchBookByAuthor(author);
        }
        else if(choice == 9)
        {
            int id;
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            lib.borrowBook(id);
        }
        else if(choice == 10)
        {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
        }
    } while(choice != 0);

    cout << "Exiting Library System...\n";
    return 0;
}
