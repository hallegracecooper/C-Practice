#include <iostream>
#include "Book.h"

int main() {
    // Create a Book object
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", 1925);

    // Display book details
    std::cout << "Book Details:\n";
    myBook.display();

    return 0;
}