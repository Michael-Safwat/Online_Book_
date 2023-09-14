#include"books_manager.h"

books_manager::books_manager()
{
	book book1;
	std::vector<std::string> lines;
	std::pair<int, std::vector<std::string>> p;

	book1.set_isbn("123456789");
	book1.set_title("C++");
	book1.set_num_of_pages(3);
	book1.set_author_name("Michael");
	
	lines.push_back("C++1");
	p = make_pair(1, lines);
	book1.set_content(p);

	lines.clear();

	lines.push_back("C++2");
	p = make_pair(2, lines);
	book1.set_content(p);

	lines.clear();

	lines.push_back("C++3");
	p = make_pair(3, lines);
	book1.set_content(p);
	
	books.push_back(book1);

	book book2;

	book2.set_isbn("987654321");
	book2.set_title("Data Structures");
	book2.set_num_of_pages(3);
	book2.set_author_name("Ayman");

	lines.clear();

	lines.push_back("DS1");
	p = make_pair(1, lines);
	book2.set_content(p);

	lines.clear();

	lines.push_back("DS2");
	p = make_pair(2, lines);
	book2.set_content(p);

	lines.clear();

	lines.push_back("DS3");
	p = make_pair(3, lines);
	book2.set_content(p);

	books.push_back(book2);
}

const std::vector<book>& books_manager::get_books()const
{
	return books;
}
void books_manager::get_books_names()
{
	books_names.clear();
	for (auto book : books)
	{
		books_names.push_back(book.get_title());
	}
}

void books_manager::add_book()
{
	book book;
	std::string str;
	std::cout << "Enter ISBN: ";
	std::cin >> str;
	book.set_isbn(str);

	std::cout << "Enter Book Title: ";
	std::cin.ignore();
	getline(std::cin, str);
	book.set_title(str);

	std::cout << "Enter Book Author Name: ";
	std::cin.ignore();
	getline(std::cin, str);
	book.set_author_name(str);

	std::cout << "Enter number of pages of the Book: ";
	int num_of_pages;
	std::cin >> num_of_pages;
	book.set_num_of_pages(num_of_pages);

	book.write_book_content();
	books.push_back(book);
}
book books_manager::select_from_reading_history(std::vector<book> sessions)
{
	for (int i = 1; i <= sessions.size(); i++)
	{
		std::cout << i << ": " << sessions[i - 1].get_title() << ": " << sessions[i - 1].get_last_opened_page() << "/"
			<< sessions[i - 1].get_num_of_pages() << " - " << std::ctime(&(sessions[i - 1].get_last_reading_time()));
	}
	std::cout << "Which session to open?: \n";
	book chosen_session;
	chosen_session=sessions[read_choice(sessions.size())-1];
	return book_navigation(chosen_session, chosen_session.get_last_opened_page());
}
book books_manager::list_select_available_books()
{
	std::cout << "Our current Book collection: \n";
	get_books_names();
	menu(books_names);
	std::cout << "\nWhich Book to read?:";
	book chosen_book;
	chosen_book = books[read_choice(books.size())-1];
	return book_navigation(chosen_book);
}
book books_manager::book_navigation(book& chosen_book,int current_page)
{
	std::vector<std::string> choices;
	choices.push_back("Next Page");
	choices.push_back("Previous Page");
	choices.push_back("Stop Reading");

	std::cout << "Opened " << chosen_book.get_title() << " Book\n";

	bool run = true;
	while (run)
	{
		std::cout << "Current page: " << current_page << "/" << chosen_book.get_num_of_pages() << "\n";
		chosen_book.print_book_content(current_page);
		std::cout << "Menu:\n";
		
		menu(choices);
		switch (read_choice(choices.size()))
		{
		case 1:
			if (current_page == chosen_book.get_num_of_pages())
				continue;
			current_page++;
			break;
		case 2:
			if (current_page == 1)
				continue;
			current_page--;
			break;
		case 3:
			run = false;
			auto end_time = std::chrono::system_clock::now();
			chosen_book.set_last_reading_time(std::chrono::system_clock::to_time_t(end_time));
			chosen_book.set_last_opened_page(current_page);
			break;
		}
	}
	return chosen_book;
}