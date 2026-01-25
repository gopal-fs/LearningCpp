#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book() : id(0), issued(false) {}
    Book(int id, const string& title, const string& author)
        : id(id), title(title), author(author), issued(false) {}
};

class Library {
    vector<Book> books;
    int nextId = 1;

    int findIndexById(int id) {
        for (int i = 0; i < (int)books.size(); i++) {
            if (books[i].id == id) return i;
        }
        return -1;
    }

public:
    void addBook() {
        string title, author;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, title);
        getline(cin, author);

        books.push_back(Book(nextId, title, author));
        cout << "Added " << nextId << "\n";
        nextId++;
    }

    void listBooks() {
        if (books.empty()) {
            cout << "Empty\n";
            return;
        }
        for (auto &b : books) {
            cout << b.id << " | " << b.title << " | " << b.author << " | "
                 << (b.issued ? "Issued" : "Available") << "\n";
        }
    }

    void searchByTitle() {
        string key;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, key);

        bool found = false;
        for (auto &b : books) {
            if (b.title.find(key) != string::npos) {
                cout << b.id << " | " << b.title << " | " << b.author << " | "
                     << (b.issued ? "Issued" : "Available") << "\n";
                found = true;
            }
        }
        if (!found) cout << "NotFound\n";
    }

    void issueBook() {
        int id;
        cin >> id;
        int idx = findIndexById(id);
        if (idx == -1) {
            cout << "NotFound\n";
            return;
        }
        if (books[idx].issued) {
            cout << "AlreadyIssued\n";
            return;
        }
        books[idx].issued = true;
        cout << "Issued\n";
    }

    void returnBook() {
        int id;
        cin >> id;
        int idx = findIndexById(id);
        if (idx == -1) {
            cout << "NotFound\n";
            return;
        }
        if (!books[idx].issued) {
            cout << "NotIssued\n";
            return;
        }
        books[idx].issued = false;
        cout << "Returned\n";
    }

    void removeBook() {
        int id;
        cin >> id;
        int idx = findIndexById(id);
        if (idx == -1) {
            cout << "NotFound\n";
            return;
        }
        books.erase(books.begin() + idx);
        cout << "Removed\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Library lib;
    int choice;

    while (true) {
        cout << "1.Add\n2.List\n3.SearchTitle\n4.Issue\n5.Return\n6.Remove\n7.Exit\n";
        if (!(cin >> choice)) break;

        if (choice == 1) lib.addBook();
        else if (choice == 2) lib.listBooks();
        else if (choice == 3) lib.searchByTitle();
        else if (choice == 4) lib.issueBook();
        else if (choice == 5) lib.returnBook();
        else if (choice == 6) lib.removeBook();
        else if (choice == 7) break;
        else cout << "Invalid\n";
    }

    return 0;
}
