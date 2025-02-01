#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    // Constructor
    Book(std::string title, std::string author, int year);

    // Getter methods
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;

    // Method to display book details
    void display() const;

    // Method to save book to file
    void saveToFile(std::ofstream &out) const;

    // Static method to load books from file
    static void loadFromFile(std::ifstream &in, std::vector<Book> &books);
};

#endif