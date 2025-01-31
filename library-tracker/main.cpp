#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Book.h"

void addBook(std::vector<Book>& books) {
    std::string title, author;
    int year;

    std::cout << "Enter book title: ";
    std::getline(std::cin, title);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    std::cout << "Enter year: ";
    std::cin >> year;
    std::cin.ignore(); // Ignore leftover newline

    books.push_back(Book(title, author, year));
    std::cout << "Book added successfully!\n";
}

void displayBooks(const std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books in the collection.\n";
        return;
    }

    std::cout << "\nBook Collection:\n";
    for (const auto& book : books) {
        book.display();
        std::cout << "--------------------\n";
    }
}

void saveBooksToFile(const std::vector<Book>& books, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "Error opening file for writing.\n";
        return;
    }

    for (const auto& book : books) {
        outFile << book.getTitle() << "\n"
                << book.getAuthor() << "\n"
                << book.getYear() << "\n";
    }

    std::cout << "Books saved to " << filename << "\n";
}

void loadBooksFromFile(std::vector<Book>& books, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cout << "No books file found. Starting with an empty collection.\n";
        return;
    }

    std::string title, author;
    int year;
    while (std::getline(inFile, title) && std::getline(inFile, author) && inFile >> year) {
        inFile.ignore();  // Ignore the newline after the year
        books.push_back(Book(title, author, year));
    }

    std::cout << "Books loaded from " << filename << "\n";
}

int main() {
    std::vector<Book> books;
    loadBooksFromFile(books, "books.txt"); // Load books from the file at the start

    int choice;

    while (true) {
        std::cout << "\nLibrary Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "3. Save Books\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline

        if (choice == 1) {
            addBook(books);
        } else if (choice == 2) {
            displayBooks(books);
        } else if (choice == 3) {
            saveBooksToFile(books, "books.txt");
        } else if (choice == 4) {
            std::cout << "Exiting program...\n";
            break;
        } else {
            std::cout << "Invalid option, try again.\n";
        }
    }

    return 0;
}