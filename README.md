Project Name: Online Library Management System (ASSIGNMENT 1)
Course: Bachelor of Science in Software Engineering (BSE)
Unit: Object Oriented Programming (OOP)
Name: Shalom Lamo
Adm no: BSE-05-0104/2025
Date: 6th February 2026

Introduction
- This project is a simple Online Library Management System that is created using Object Oriented Programming Principles in C++ language.
- Real-world entities such as Books, Users and the library itself can be included and easily defined with the classes and objects feature of C++ hence OOP is the most suitable for this project.

Designing of the classes
- For the library system, we are dealing with three classes:
1.Books.
2.Users.
3.Library.

1. Book class
- A book should have a bookID, a title, the author of the book and whether the book is available for borrowing or not(‘isAvailable’ boolean variable) These form the attributes of the book class.
- We will use the displayBook() member function which displays book details including availability.

2. User Class
- Attributes: userID, name
- Methods: displayUser() member function

3. Library Class
- Attributes:  arrays of Books and Users (here, we can give an exact number of books and users that the system will manage e.g 100), counters for bookCount and userCount so as to keep track of added books or users up to the limited number.
- Methods:
  
I) addBook()
II) removeBook()
III) showBooks()             <--------- Book-related functions
IV) searchBookByTitle()
V) searchBookByAuthor()
                     
I)addUser()
II)removeUser()             <--------- User-related functions
III)showUsers()

I)borrowBook()
II)returnBook()             <--------- Borrow/Return functions


Main Program Flow
- The main() function interacts with the library by:
I)Creating a Library object.
II)Showing a menu whereby the user interacts with the system(User Interface).
III)Calls Library methods based on user choices.
