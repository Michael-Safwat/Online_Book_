#pragma once
#pragma warning(disable : 4996)
#include<chrono>
#include<ctime>
#include"book.h"
#include"api.h"

class books_manager
{
private:
	std::vector<book> books;
	std::vector<std::string> books_names;

public:
	books_manager();

	const std::vector<book>& get_books()const;

	void add_book();
	void get_books_names();
	book select_from_reading_history(std::vector<book> sessions);
	book list_select_available_books();
	book book_navigation(book& chosen_book,int current_page=1);
};
