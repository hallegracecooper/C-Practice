#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>
#include "Book.h"

void loadBooksFromFile(std::map<std::string, Book> &books);
void saveBooksToFile(const std::map<std::string, Book> &books);
void addBook(std::map<std::string, Book> &books);
void displayBooks(const std::map<std::string, Book> &books);

int main() {
    std::map<std::string, Book> books;  // Use map instead of vector to store books

    loadBooksFromFile(books);  // Load books from file

    int choice;
    do {
        std::cout << "\nLibrary Tracker Menu:\n";
        std::cout << "1. Add a book\n";
        std::cout << "2. Save books to file\n";
        std::cout << "3. Display all books\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // To consume the newline character from the previous input

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

void loadBooksFromFile(std::map<std::string, Book> &books) {
    std::ifstream inFile("books.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening file to load books.\n";
        return;
    }

    Book::loadFromFile(inFile, books);  // Load books into the map
    std::cout << "Books loaded from file successfully.\n";
    inFile.close();
}

void saveBooksToFile(const std::map<std::string, Book> &books) {
    std::ofstream outFile("books.txt");

    if (!outFile.is_open()) {
        std::cerr << "Error opening file to save books.\n";
        return;
    }

    for (const auto &pair : books) {
        pair.second.saveToFile(outFile);  // Save each book to the file
    }

    std::cout << "Books saved to file successfully.\n";
    outFile.close();
}

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

    // Create Book object and add to the map using title as the key
    Book newBook(title, author, year);
    books[title] = newBook;
}

void displayBooks(const std::map<std::string, Book> &books) {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }

    std::cout << "Books in the library:\n";
    for (const auto &pair : books) {
        const Book &book = pair.second;
        std::cout << "Title: " << book.getTitle() << "\n";
        std::cout << "Author: " << book.getAuthor() << "\n";
        std::cout << "Year: " << book.getYear() << "\n";
        std::cout << "-----------------------\n";
    }
}