#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    // Constructor
    Book(string t, string a, string i) : title(t), author(a), isbn(i), available(true) {}

    // Methods
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailability(bool status) {
        available = status;
    }

    string getTitle() const {
        return title;
    }
};

class Library {
private:
    vector<Book> books;

public:
    // Methods
    void addBook(const Book& b) {
        books.push_back(b);
    }

    void displayBooks() const {
        cout << "Library Catalog:" << endl;
        for (const auto& book : books) {
            book.displayInfo();
            cout << "---------------------" << endl;
        }
    }

    void checkOutBook(const string& title) {
        for (auto& book : books) {
            if (book.isAvailable() && book.getTitle() == title) {
                book.setAvailability(false);
                cout << "Book '" << title << "' checked out successfully." << endl;
                return;
            }
        }
        cout << "Book '" << title << "' is not available for checkout." << endl;
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (!book.isAvailable() && book.getTitle() == title) {
                book.setAvailability(true);
                cout << "Book '" << title << "' returned successfully." << endl;
                return;
            }
        }
        cout << "Invalid return: Book '" << title << "' was not checked out." << endl;
    }
};

int main() {
    Library library;

    // Adding sample books
    Book book1("Book1", "Author1", "123456789");
    Book book2("Book2", "Author2", "987654321");

    library.addBook(book1);
    library.addBook(book2);

    // Display available books
    cout << "Available Books:" << endl;
    library.displayBooks();

    // Checking out a book
    cout << "\nChecking out 'Book1'..." << endl;
    library.checkOutBook("Book1");

    // Display available books after checkout
    cout << "\nAvailable Books after checkout:" << endl;
    library.displayBooks();

    return 0;
}
