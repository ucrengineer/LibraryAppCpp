#pragma once
#include <string>
class Book
{
public:
	int Id;
	std::string Title;
	std::string Author;
	bool CheckOut;

	//constructor
	Book(int id, std::string title, std::string author);

};

