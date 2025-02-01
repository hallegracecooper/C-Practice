#include "Book.h"

// Constructor
Book::Book(std::string title, std::string author, int year)
    : title(title), author(author), year(year) {}

// Getter methods
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

// Display book details
void Book::display() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Year: " << year << "\n";
}

// Save book to file
void Book::saveToFile(std::ofstream &out) const {
    out << title << "," << author << "," << year << "\n";
}

// Load books from file
void Book::loadFromFile(std::ifstream &in, std::vector<Book> &books) {
    std::string title, author;
    int year;
    
    while (getline(in, title, ',') && getline(in, author, ',') && in >> year) {
        in.ignore();  // Ignore newline character after year
        
        // Create Book object and add to vector
        Book loadedBook(title, author, year);
        books.push_back(loadedBook);
    }
}