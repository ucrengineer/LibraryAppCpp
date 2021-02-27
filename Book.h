#pragma once
#include <string>
class Book
{
public:
	int Id;
	std::string Title;
	std::string Author;
	bool CheckedOut;

	//constructor
	Book();
	Book(int id, std::string title, std::string author);

	// takes in the address of the book
	bool operator ==(const Book &book) const
	{
		// if the title address storage is the same as the 
		// the other books title address storage..
		// comparing variable address locations instead of actual strings..smart
		if (Title.compare(book.Title) == 0)
			return true;
		else
			return false;
	}
};

