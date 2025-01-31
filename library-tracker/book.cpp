#include "Book.h"

Book::Book(std::string title, std::string author, int year)
    : title(title), author(author), year(year) {}

void Book::display() const {
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "Year: " << year << "\n";
}
