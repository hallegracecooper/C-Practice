#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    // Constructor
    Book(std::string title, std::string author, int year);

    // Display book details
    void display() const;
};

#endif