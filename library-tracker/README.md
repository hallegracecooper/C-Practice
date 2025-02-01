# C-Practice
CSE 310 Module 2


# Library Book Tracker  

## Description  
A simple C++ program to manage a library of books by allowing users to add, search, display, and save book information.  

## Features  
- Add books with title, author, and ISBN.  
- Save and load books from a file.  
- Search for books by title or author.  

## How to Run  
Instructions on compiling and running the program will be added here.  

# Library Tracker

This is a simple library tracker program in C++ that allows users to add, display, and save books to a file. It uses `std::map` to store books, where each book is identified by its title. Books are loaded from a file and can be saved back to the file after modifications.

## Features
- Add a new book to the library
- Display all books in the library
- Save the current list of books to a file
- Books are saved and loaded from a text file (`books.txt`)

## How to Use

1. Compile the program using a C++ compiler.
    ```bash
    g++ main.cpp Book.cpp -o library
    ```

2. Run the compiled program:
    ```bash
    ./library  # For Linux/macOS
    library.exe  # For Windows
    ```

3. Follow the on-screen menu to:
    - Add a new book
    - Save books to file
    - Display all books

4. Exit the program when done.

## File Structure
- `main.cpp`: The main program logic.
- `Book.h`: Header file for the `Book` class.
- `Book.cpp`: Implementation file for the `Book` class.
- `books.txt`: File where books are stored.

## License
This project is open-source and available under the [MIT License](LICENSE).
