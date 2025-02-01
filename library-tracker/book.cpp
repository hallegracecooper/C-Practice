#include "Book.h"

Book::Book(std::string title, std::string author, int year)
    : title(title), author(author), year(year) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

void Book::display() const {
    std::cout << "Title: " << title << "\nAuthor: " << author << "\nYear: " << year << std::endl;
}

void Book::saveToFile(std::ofstream &outFile) const {
    outFile << title << "," << author << "," << year << "\n";
}

void Book::loadFromFile(std::ifstream &inFile, std::map<std::string, Book> &books) {
    std::string title, author;
    int year;
    while (inFile >> title >> author >> year) {
        books[title] = Book(title, author, year);
    }
}