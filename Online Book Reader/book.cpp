#include"book.h"

book::book():num_of_pages(0),last_opened_paged(0)
{

}

const std::string& book::get_isbn()const
{
	return isbn;
}
void book::set_isbn(const std::string& isbn)
{
	this->isbn = isbn;
}

const std::string& book::get_title()const
{
	return title;
}
void book::set_title(const std::string& title)
{
	this->title = title;
}

const std::string& book::get_author_name()const
{
	return author_name;
}
void book::set_author_name(const std::string& author_name)
{
	this->author_name = author_name;
}

const int book::get_num_of_pages()const
{
	return num_of_pages;
}
void book::set_num_of_pages(const int num_of_pages)
{
	this->num_of_pages = num_of_pages;
}

const int book::get_last_opened_page()const
{
	return last_opened_paged;
}
void book::set_last_opened_page(const int last_opened_page)
{
	this->last_opened_paged = last_opened_page;
}

const time_t& book::get_last_reading_time()const
{
	return last_reading_time;
}
void book::set_last_reading_time(const time_t& last_reading_time)
{
	this->last_reading_time = last_reading_time;
}

void book::set_content(std::pair<int, std::vector<std::string>>& page_content)
{
	content.insert(page_content);
}
void book::write_book_content()
{
	std::cout << "Enter ~ to end the content of each page to end it's content\n";
	for (int i = 1; i <= num_of_pages; i++)
	{
		std::string line;
		std::vector<std::string>lines;

		std::cout << "Enter page #" << i << " content: ";
		while (line != "~")
		{
			getline(std::cin, line);
			if (line != "~")
				lines.push_back(line);
		}
		content[i] = lines;
	}
}
void book::print_book_content(const int current_page)
{
	for (auto line : content[current_page])
	{
		std::cout << line << "\n";
	}
}