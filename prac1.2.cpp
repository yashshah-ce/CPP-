#include <iostream>
#include <string>
using namespace std;

int bookId[100];
string title[100];
string author[100];
int copies[100];
int totalBooks = 0;

void addBook() {
    cout << "Enter Book ID: ";
    cin >> bookId[totalBooks];
    cout << "Enter Title: ";
    cin >> title[totalBooks];
    cout << "Enter Author: ";
    cin >> author[totalBooks];
    cout << "Enter Copies: ";
    cin >> copies[totalBooks];
    totalBooks++;
}

void issueBook(int id) {
    for(int i = 0; i < totalBooks; i++) {
        if(bookId[i] == id) {
            if(copies[i] > 0) {
                copies[i]--;
                cout << "Book Issued Successfully!\n";
            } else {
                cout << "No copies available!\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void returnBook(int id) {
    for(int i = 0; i < totalBooks; i++) {
        if(bookId[i] == id) {
            copies[i]++;
            cout << "Book Returned Successfully!\n";
            return;
        }
    }
    cout << "Book not found!\n";
}

void displayTotalBooks() {
    cout << "Total Books in Library: " << totalBooks << endl;
}

int main() {
    int choice, id;
    menu:
        cout << "\n1. Add Book\n2. Issue Book\n3. Return Book\n4. Display Total Book\n5. Exit\n ";
        cout <<"Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1 :
            addBook();
            goto menu;
        case 2 :
            cout << "Enter Book ID to Issue: ";
            cin >> id;
            issueBook(id);
            goto menu;
        case 3 :
            cout << "Enter Book ID to return: ";
            cin >> id;
            returnBook(id);
            goto menu;

        case 4 :
            displayTotalBooks();
            goto menu;
        case 5 :
            cout << "Exiting Program....\n";
            break;

        default:
            cout << "Invalid Choice! Try again.../n";
            goto menu;
        }
     return 0;

}
