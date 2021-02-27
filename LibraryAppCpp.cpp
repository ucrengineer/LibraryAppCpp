#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string>
// dont use in .h files or class definition files
using namespace std;

// _global variable
Inventory _inventory;
int displayMainMenu()
{
    cout << "Choose an option:" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. List all books" << endl;
    cout << "3. Check out book" << endl;
    cout << "4. Check in book" << endl;
    cout << "5. Remove Book" << endl;
    cout << "0. Exit" << endl;
    int input;
    cin >> input;
    cin.ignore();
    return input;

}
void addNewBook()
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
}
void listAllBooks()
{
    cout << "\nID\tTitle\tAuthor" << endl;
    for (int i = 0; i < _inventory.Books.size(); i++)
    {
        cout << _inventory.Books[i].Id << "\t" <<
            _inventory.Books[i].Title << "\t" <<
            _inventory.Books[i].Author << endl;
    }
    cout << endl;
}
void checkInOrOutBook(bool checkIn)
{
    string inOrOut;
    if (checkIn)
    {
        inOrOut = "in";
    }
    else
    {
        inOrOut = "out";
    }
    cout << "Enter a book title to check " + inOrOut +": ";
    string title;
    getline(cin, title);
    int foundBookIndex = _inventory.FindBookByTitle(title);

    if (foundBookIndex >= 0)
    {
        // pointer = memory location of book
        Book* foundBook = &_inventory.Books[foundBookIndex];

        // if checkedout == false then we're checked in
        // if checkedout == true then we're checked out

        if (!foundBook->CheckedOut == checkIn)
        {
            cout << "Book already checked "+inOrOut+ "." << endl;
            return;

        }
        if (checkIn)
        {
            _inventory.CheckInBook(foundBook);
        }
        else
        {
            _inventory.CheckOutBook(foundBook);
        }
        //_inventory.CheckOutBook(foundBook);
        cout << "Book checked "+inOrOut+"!" << endl;
    }
    else
    {
        cout << "Book not found" << endl;

    }
}
void removeBook()
{
    cout << "Title:";
    string title;
    // getline gets multiple words, cin only gets one word
    getline(cin, title);

    _inventory.RemoveBook(title);
    cout << "Book named: " << title << " removed!" << endl;
}

int main()
{
    while (true) 
    {
      
        int input = displayMainMenu();
      

        switch (input)
        {
            case 0:
                cout << "Thank you. Goodbye";
                return 0;
            case 1: 
            {
                addNewBook();
                break;
            }
        
            case 2:
            {
                listAllBooks();
                break;

            }
            case 3:
            {
                checkInOrOutBook(false);

                break;

            }
            case 4: 
            {
          
                checkInOrOutBook(true);
                break;

            }
            case 5:
            {
                removeBook();
                break;
            }
            default:
                cout << "Invalid selection. Try again." << endl;
                break;
            }

    }
    return 0;
}

