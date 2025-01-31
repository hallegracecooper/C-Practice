#include <iostream>
#include <vector>
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

int main() {
    std::vector<Book> books;
    int choice;

    while (true) {
        std::cout << "\nLibrary Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline

        if (choice == 1) {
            addBook(books);
        } else if (choice == 2) {
            displayBooks(books);
        } else if (choice == 3) {
            std::cout << "Exiting program...\n";
            break;
        } else {
            std::cout << "Invalid option, try again.\n";
        }
    }

    return 0;
}