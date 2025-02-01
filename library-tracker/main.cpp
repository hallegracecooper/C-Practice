#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>
#include "Book.h"

// Function prototypes
void loadBooksFromFile(std::map<std::string, Book> &books);  // Function to load books from file
void saveBooksToFile(const std::map<std::string, Book> &books);  // Function to save books to file
void addBook(std::map<std::string, Book> &books);  // Function to add a new book
void displayBooks(const std::map<std::string, Book> &books);  // Function to display all books

int main() {
    // Use a map to store books, where the key is the book title
    std::map<std::string, Book> books;

    // Load books from file at the beginning of the program
    loadBooksFromFile(books);

    int choice;
    do {
        // Display the menu and get user choice
        std::cout << "\nLibrary Tracker Menu:\n";
        std::cout << "1. Add a book\n";
        std::cout << "2. Save books to file\n";
        std::cout << "3. Display all books\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // To consume the newline character from previous input

        switch (choice) {
            case 1:
                addBook(books);  // Add a new book
                break;
            case 2:
                saveBooksToFile(books);  // Save books to file
                break;
            case 3:
                displayBooks(books);  // Display all books
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to load books from a file into the map
void loadBooksFromFile(std::map<std::string, Book> &books) {
    std::ifstream inFile("books.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening file to load books.\n";
        return;
    }

    // Load books into the map using Book::loadFromFile
    Book::loadFromFile(inFile, books);
    std::cout << "Books loaded from file successfully.\n";
    inFile.close();
}

// Function to save books to a file
void saveBooksToFile(const std::map<std::string, Book> &books) {
    std::ofstream outFile("books.txt");

    if (!outFile.is_open()) {
        std::cerr << "Error opening file to save books.\n";
        return;
    }

    // Save each book in the map to the file
    for (const auto &pair : books) {
        pair.second.saveToFile(outFile);
    }

    std::cout << "Books saved to file successfully.\n";
    outFile.close();
}

// Function to add a new book to the library
void addBook(std::map<std::string, Book> &books) {
    std::string title, author;
    int year;

    // Input details for a new book
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);

    // Input validation for year
    std::cout << "Enter publication year: ";
    while (!(std::cin >> year)) {
        std::cout << "Invalid year. Please enter a valid year: ";
        std::cin.clear();  // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard invalid input
    }
    std::cin.ignore();  // To clear the newline from the buffer

    // Create a new book object and add it to the map
    Book newBook(title, author, year);
    books[title] = newBook;
}

// Function to display all books in the library
void displayBooks(const std::map<std::string, Book> &books) {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }

    std::cout << "Books in the library:\n";
    // Iterate over the map and display each book's details
    for (const auto &pair : books) {
        const Book &book = pair.second;
        std::cout << "Title: " << book.getTitle() << "\n";
        std::cout << "Author: " << book.getAuthor() << "\n";
        std::cout << "Year: " << book.getYear() << "\n";
        std::cout << "-----------------------\n";
    }
}