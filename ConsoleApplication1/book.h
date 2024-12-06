#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    // Constructor with proper validation
    Book(string t, string a, string i, int avl, string date) {
        if (t.empty() || a.empty() || i.empty() || date.empty()) {
            throw invalid_argument("Fields cannot be empty.");
        }
        if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
            throw invalid_argument("Date format should be YYYY-MM-DD.");
        }
        if (i.find_first_not_of("0123456789") != string::npos) {
            throw invalid_argument("ISBN must be numeric.");
        }
        // Validate availability (should strictly be 0 or 1)
        if (avl != 0 && avl != 1) {
            throw invalid_argument("Invalid availability value.");
        }

        title = t;
        author = a;
        isbn = i;
        available = (avl == 1);
        dateAdded = date;
    }

    // Display book details
    void displayBookDetails() const {
        cout << "Title: " << title
            << ", Author: " << author
            << ", ISBN: " << isbn
            << ", Availability: " << (available ? "Available" : "Borrowed")
            << ", Date Added: " << dateAdded << endl;
    }
};

#endif // BOOK_H
