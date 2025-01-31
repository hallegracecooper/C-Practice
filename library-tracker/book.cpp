#include "Book.h"

// Constructor
Book::Book(std::string title, std::string author, int year)
    : title(title), author(author), year(year) {}

// Display book details
void Book::display() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Year: " << year << "\n";
}