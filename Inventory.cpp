#include "Inventory.h"

void Inventory::AddBook(Book book) 
{
	Inventory::Books.push_back(book);
}
void Inventory::RemoveBook(std::string title)
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));

	if (it != Inventory::Books.end())
	{
		Inventory::Books.erase(it);
	}

}
int Inventory::FindBookByTitle(std::string title)
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));

	if ( it == Inventory::Books.end())
	{
		
		return -1;
	}
	int index = it - Inventory::Books.begin();
	return false;


}
// input the reference of the book so that the value can actually be changed.
void Inventory::CheckOutBook(Book *book)
{
	book->CheckedOut = true;
}
void Inventory::CheckInBook(Book *book)
{
	book->CheckedOut = false;
}
