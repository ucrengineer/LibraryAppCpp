#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string>
// dont use in .h files or class definition files
using namespace std;

// _global variable
Inventory _inventory;

int main()
{
    while (true) 
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. List all books" << endl;
        cout << "3. Check out book" << endl;
        cout << "4. Check in book" << endl;

        cout << "0. Exit" << endl;


        int input;
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 0:
            cout << "Thank you. Goodbye";
            return 0;
        case 1: 
        {
            cout << "Title:";
            string title;
            // getline gets multiple words, cin only gets one word
            getline(cin, title);
            cout << "Author:";
            string author;
            // getline gets multiple words, cin only gets one word
            getline(cin, author);

            int id = _inventory.Books.size() + 1;
            Book newBook(id, title, author);
        
            _inventory.AddBook(newBook);
            break;
        }
        
        case 2:
        {
            cout << "\nID\tTitle\tAuthor" << endl;
            for (int i = 0; i < _inventory.Books.size(); i++) 
            {
                cout << _inventory.Books[i].Id << "\t" <<
                    _inventory.Books[i].Title << "\t" <<
                    _inventory.Books[i].Author << endl;
            }
            cout << endl;
            break;

        }
        case 3:
        {
            cout << "Enter a book title to check out: ";
            string title;
            getline(cin, title);
            Book foundBook;
            if (_inventory.FindBookByTitle(title, foundBook)) 
            {
                if (!foundBook.CheckedOut)
                {
                    cout << "Book already checked in" << endl;
                    break;

                }
                _inventory.CheckOutBook(foundBook);
                cout << "Book checked out!" << endl;
            }
            else
            {
                cout << "Book not found" << endl;

            }

            break;

        }
        case 4: 
        {
            cout << "Enter a book title to check in: ";
            string title;
            getline(cin, title);
            Book foundBook;
            if (_inventory.FindBookByTitle(title, foundBook))
            {
                if (!foundBook.CheckedOut)
                {
                    cout << "Book already checked in" << endl;
                    break;

                }
                
                _inventory.CheckInBook(foundBook);
                cout << "Book checked in!" << endl;
            }
            else
            {
                cout << "Book not found" << endl;

            }

            break;

        }
        default:
            cout << "Invalid selection. Try again." << endl;
            break;
        }

    }
    return 0;
}

