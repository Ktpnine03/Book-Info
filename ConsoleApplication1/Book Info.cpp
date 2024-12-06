#include "Book.h"

int main() {
    cout << "=== Correct Book's Information ===" << endl;
    try {
        // Correct initialization with matching argument types
        Book book1("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "00523", true, "2022-03-15");
        Book book2("Moby Dick", "Herman Melville", "27089", true, "2022-12-25");
        Book book3("To Kill a Mockingbird", "Harper Lee", "15368", true, "2022-06-20");

        book1.displayBookDetails();
        book2.displayBookDetails();
        book3.displayBookDetails();
    }
    catch (const exception& e) {
        cout << "Error during correct initialization: " << e.what() << endl;
    }

    cout << "\n=== Incorrect Book's Information ===" << endl;

    // Incorrect initializations
    try {
        // Incorrect title type: passing an integer instead of string
        Book book4("1984", "George Orwell", "wrong_isbn", true, "2023-01-01");
        book4.displayBookDetails();
    }
    catch (const exception& e) {
        cout << "Book 4 initialization failed: " << e.what() << endl;
    }

    try {
        // Incorrect ISBN and date format
        Book book5("Moby Dick", "Herman Melville", "wrong_isbn", true, "12-35-9999");
        book5.displayBookDetails();
    }
    catch (const exception& e) {
        cout << "Book 5 initialization failed: " << e.what() << endl;
    }

    try {
        // Invalid availability value: passing an integer instead of a boolean
        Book book6("Pride and Prejudice", "Jane Austen", "22003", 5, "2023-09-05");
        book6.displayBookDetails();
    }
    catch (const exception& e) {
        cout << "Book 6 initialization failed: " << e.what() << endl;
    }

    return 0;
}
