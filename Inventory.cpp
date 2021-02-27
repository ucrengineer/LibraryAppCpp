#include "Inventory.h"

void Inventory::AddBook(Book book) 
{
	Inventory::Books.push_back(book);
}

bool Inventory::FindBookByTitle(std::string title, Book &book)
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));

	if ( it != Inventory::Books.end())
	{
		book = *it;
		return true;

	}

	return false;


}
// input the reference of the book so that the value can actually be changed.
void Inventory::CheckOutBook(Book &book)
{
	book.CheckedOut = true;
}
void Inventory::CheckInBook(Book &book)
{
	book.CheckedOut = false;
}
void Inventory::RemoveBook(Book book)
{
	Inventory::Books.pop_back();
}