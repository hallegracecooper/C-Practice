#include "Book.h"

// Constructor to initialize book details
Book::Book(const string& t, const string& a, const string& i) {
    title = t;
    author = a;
    isbn = i;
}

// Getter method definitions (optional)
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getIsbn() const {
    return isbn;
}
