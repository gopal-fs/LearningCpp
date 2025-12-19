#include <iostream>
#include <string>
using namespace std;

class Book{
    public:
        int id;
        string name;
    Book(){
        id=0;
        name="";
    }

};

class Admin {
public:
    Book books[20];   
    int bookCount;

    Admin() {
        bookCount = 0; 
    }

        void addBook() {
        if (bookCount >= 20) {
            cout << "Library Full!" << endl;
            return;
        }

        cout << "Enter Book ID: ";
        cin >> books[bookCount].id;

        cin.ignore();
        cout << "Enter Book Name: ";
        getline(cin, books[bookCount].name);

        bookCount++;
        cout << "Book Added Successfully!" << endl;
    }

        void viewBooks() {
        if (bookCount == 0) {
            cout << "No Books Available!" << endl;
            return;
        }

        for (int i = 0; i < bookCount; i++) {
            cout << books[i].id << " - " << books[i].name << endl;
        }
    }

        void deleteBook(int id) {
        int index = -1;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Book Not Found!" << endl;
            return;
        }

        for (int i = index; i < bookCount - 1; i++) {
            books[i] = books[i + 1];
        }

        bookCount--;
        cout << "Book Deleted Successfully!" << endl;
    }
};



int main() {
    cout << "############### SMART LIBRARY MANAGEMENT SYSTEM ##############" << endl;

    int role;
    do {
        cout << "Please Choose One [1.Admin, 2.Student]: ";
        cin >> role;
    } while (!(role == 1 || role == 2));

    string user = (role == 1) ? "Admin" : "Student";
    cout << "Logging In As " << user << endl;

    if (user == "Admin") {
        Admin admin;
int op;

do {
    cout << "\n1.Add Book\n2.View Books\n3.Delete Book\n4.Exit\n";
    cout << "Choose: ";
    cin >> op;

    switch (op) {
        case 1:
            admin.addBook();
            break;
        case 2:
            admin.viewBooks();
            break;
        case 3: {
            int id;
            cout << "Enter Book ID to delete: ";
            cin >> id;
            admin.deleteBook(id);
            break;
        }
    }
} while (op != 4);

    }

    cout << "############### END ##############" << endl;
    return 0;
}
