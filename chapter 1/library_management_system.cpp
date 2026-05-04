#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// Helper function for case-insensitive search
string toLower(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

// ==========================================
// Book Class
// ==========================================
class Book {
public:
    int book_id;
    string title;
    string author;
    bool is_issued;

    Book(int id, string t, string a) : book_id(id), title(t), author(a), is_issued(false) {}

    void display() const {
        string status = is_issued ? "Issued" : "Available";
        cout << "[ID: " << book_id << "] '" << title << "' by " << author << " - " << status << "\n";
    }
};

// ==========================================
// Member Class
// ==========================================
class Member {
public:
    int member_id;
    string name;
    vector<int> borrowed_books; // Store IDs of borrowed books

    Member(int id, string n) : member_id(id), name(n) {}

    void display() const {
        cout << "[ID: " << member_id << "] " << name 
             << " (Borrowed: " << borrowed_books.size() << " books)\n";
    }
};

// ==========================================
// Library Class
// ==========================================
class Library {
private:
    vector<Book> books;
    vector<Member> members;
    int next_book_id = 1;
    int next_member_id = 1;

    // Helper methods to find objects by ID
    Book* find_book(int id) {
        for (auto& book : books) {
            if (book.book_id == id) return &book;
        }
        return nullptr;
    }

    Member* find_member(int id) {
        for (auto& member : members) {
            if (member.member_id == id) return &member;
        }
        return nullptr;
    }

public:
    // --- Book Management ---
    void add_book(const string& title, const string& author) {
        books.push_back(Book(next_book_id++, title, author));
        cout << "Success: '" << title << "' added to the library.\n";
    }

    void search_books(const string& query, const string& search_by) {
        bool found = false;
        string lower_query = toLower(query);

        cout << "\n--- Search Results ---\n";
        for (const auto& book : books) {
            string target = (search_by == "title") ? book.title : book.author;
            if (toLower(target).find(lower_query) != string::npos) {
                book.display();
                found = true;
            }
        }

        if (!found) {
            cout << "No books found matching '" << query << "'.\n";
        }
    }

    void display_all_books() const {
        if (books.empty()) {
            cout << "The library currently has no books.\n";
            return;
        }
        cout << "\n--- All Library Books ---\n";
        for (const auto& book : books) {
            book.display();
        }
    }

    // --- Member Management ---
    void add_member(const string& name) {
        members.push_back(Member(next_member_id++, name));
        cout << "Success: Member '" << name << "' added successfully.\n";
    }

    // --- Issue and Return ---
    void issue_book(int book_id, int member_id) {
        Book* book = find_book(book_id);
        Member* member = find_member(member_id);

        if (!book) {
            cout << "Error: Book not found.\n";
            return;
        }
        if (!member) {
            cout << "Error: Member not found.\n";
            return;
        }
        if (book->is_issued) {
            cout << "Error: This book is already issued to someone else.\n";
            return;
        }

        book->is_issued = true;
        member->borrowed_books.push_back(book_id);
        cout << "Success: '" << book->title << "' has been issued to " << member->name << ".\n";
    }

    void return_book(int book_id, int member_id) {
        Book* book = find_book(book_id);
        Member* member = find_member(member_id);

        if (!book) {
            cout << "Error: Book not found.\n";
            return;
        }
        if (!member) {
            cout << "Error: Member not found.\n";
            return;
        }

        // Check if member actually borrowed this book
        auto it = find(member->borrowed_books.begin(), member->borrowed_books.end(), book_id);
        if (it == member->borrowed_books.end()) {
            cout << "Error: This member did not borrow this book.\n";
            return;
        }

        book->is_issued = false;
        member->borrowed_books.erase(it);
        cout << "Success: '" << book->title << "' has been returned by " << member->name << ".\n";
    }
};

// ==========================================
// Main Interface
// ==========================================
int main() {
    Library library;

    // Pre-populate with sample data
    library.add_book("The Great Gatsby", "F. Scott Fitzgerald");
    library.add_book("1984", "George Orwell");
    library.add_book("To Kill a Mockingbird", "Harper Lee");
    library.add_member("Alice Smith");
    library.add_member("Bob Jones");

    int choice;
    while (true) {
        cout << "\n==============================\n";
        cout << "  LIBRARY MANAGEMENT SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Add a Book\n";
        cout << "2. Add a Member\n";
        cout << "3. View All Books\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Search Book by Author\n";
        cout << "6. Issue a Book\n";
        cout << "7. Return a Book\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-8): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        string title, author, name, query;
        int book_id, member_id;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin >> ws, title); // ws consumes leading whitespace
                cout << "Enter book author: ";
                getline(cin >> ws, author);
                library.add_book(title, author);
                break;
            case 2:
                cout << "Enter member name: ";
                getline(cin >> ws, name);
                library.add_member(name);
                break;
            case 3:
                library.display_all_books();
                break;
            case 4:
                cout << "Enter title to search: ";
                getline(cin >> ws, query);
                library.search_books(query, "title");
                break;
            case 5:
                cout << "Enter author to search: ";
                getline(cin >> ws, query);
                library.search_books(query, "author");
                break;
            case 6:
                cout << "Enter Book ID to issue: ";
                cin >> book_id;
                cout << "Enter Member ID receiving the book: ";
                cin >> member_id;
                library.issue_book(book_id, member_id);
                break;
            case 7:
                cout << "Enter Book ID to return: ";
                cin >> book_id;
                cout << "Enter Member ID returning the book: ";
                cin >> member_id;
                library.return_book(book_id, member_id);
                break;
            case 8:
                cout << "Exiting Library Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a number between 1 and 8.\n";
        }
    }
    return 0;
}