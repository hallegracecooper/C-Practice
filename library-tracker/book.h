#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    // Constructor declaration
    Book(const string& t, const string& a, const string& i);

    // Getter methods for each attribute (optional)
    string getTitle() const;
    string getAuthor() const;
    string getIsbn() const;
};

#endif
