#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"

void addBook(std::vector<Book> &books) {
    std::string title, author;
    int year;

    // Input details for a new book
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter publication year: ";
    std::cin >> year;
    std::cin.ignore();  // To clear the newline from the buffer

    // Create Book object and add to the vector
    Book newBook(title, author, year);
    books.push_back(newBook);
}

void saveBooksToFile(const std::vector<Book> &books) {
    std::ofstream outFile("books.txt");

    if (outFile.is_open()) {
        for (const Book &book : books) {
            book.saveToFile(outFile);  // Save each book to the file
        }
        std::cout << "Books saved to file successfully.\n";
    } else {
        std::cout << "Error opening file to save books.\n";
    }

    outFile.close();
}

void loadBooksFromFile(std::vector<Book> &books) {
    std::ifstream inFile("books.txt");

    if (inFile.is_open()) {
        Book::loadFromFile(inFile, books);  // Load books from file
        std::cout << "Books loaded from file successfully.\n";
    } else {
        std::cout << "Error opening file to load books.\n";
    }

    inFile.close();
}

void displayBooks(const std::vector<Book> &books) {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
    } else {
        std::cout << "Books in the library:\n";
        for (const Book &book : books) {
            book.display();
            std::cout << "-----------------------\n";
        }
    }
}

int main() {
    std::vector<Book> books;  // Vector to hold books

    // Load books from file when the program starts
    loadBooksFromFile(books);

    char choice;

    // Main menu loop
    do {
        std::cout << "Library Tracker Menu:\n";
        std::cout << "1. Add a book\n";
        std::cout << "2. Save books to file\n";
        std::cout << "3. Display all books\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // To clear the newline from the buffer

        if (choice == '1') {
            addBook(books);  // Add a book to the list
        } else if (choice == '2') {
            saveBooksToFile(books);  // Save books to a file
        } else if (choice == '3') {
            displayBooks(books);  // Display all books
        }

    } while (choice != '4');  // Continue until user chooses to exit

    return 0;
}