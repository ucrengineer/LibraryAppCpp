#include "Inventory.h"

void Inventory::AddBook(Book book) 
{
	Inventory::Books.push_back(book);
}

void Inventory::RemoveBook(Book book)
{
	Inventory::Books.pop_back();
}