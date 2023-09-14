#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>

class book
{
private:
	std::string isbn;
	std::string title;
	std::string author_name;
	int num_of_pages;
	int last_opened_paged;
	time_t last_reading_time;
	std::map<int, std::vector<std::string>> content;

public:
	book();

	const std::string& get_isbn()const;
	void set_isbn(const std::string& isbn);

	const std::string& get_title()const;
	void set_title(const std::string& title);

	const std::string& get_author_name()const;
	void set_author_name(const std::string& author_name);

	const int get_num_of_pages()const;
	void set_num_of_pages(const int num_of_pages);

	const int get_last_opened_page()const;
	void set_last_opened_page(const int last_opened_page);

	const time_t& get_last_reading_time()const;
	void set_last_reading_time(const time_t& last_reading_time);

	void set_content(std::pair<int, std::vector<std::string>>& page_content);
	void write_book_content();
	void print_book_content(const int current_page);
};