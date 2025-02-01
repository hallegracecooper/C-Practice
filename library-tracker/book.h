#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>      // For std::map
#include <vector>   // For std::vector

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book(std::string title = "", std::string author = "", int year = 0);
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    void display() const;
    void saveToFile(std::ofstream &outFile) const;
    static void loadFromFile(std::ifstream &inFile, std::map<std::string, Book> &books);
};

#endif // BOOK_H