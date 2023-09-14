#include<iostream>
#include<vector>
#include<string>
#include"user.h"
#include"book.h"
#include"users_manager.h"
#include"books_manager.h"

class online_book_reader
{
private:
	user current_logged_user;
	users_manager users;
	books_manager books;

public:
	void run(bool& master)
	{
		std::vector<std::string> choices;
		choices.push_back("Login");
		choices.push_back("Sign Up");
		choices.push_back("Close Program");

		std::cout << "Menu:\n"; 
		menu(choices);
		switch (read_choice(choices.size()))
		{
		case 1:
			if (!users.login(current_logged_user))
				return;
			break;
		case 2:
			if (!users.signup(current_logged_user))
				return;
			break;
		case 3:
			master = false;
			std::cout << "Goodbye...";
			return;
		}

		std::cout << "Hello " << current_logged_user.get_name() << " | ";

		if (current_logged_user.get_is_admin())
		{
			std::cout << "Admin view\n\n";
			choices.clear();
			choices.push_back("View Profile");
			choices.push_back("Add Book");
			choices.push_back("Logout");

			bool run = true;
			while (run)
			{
				menu(choices);
				switch (read_choice(choices.size()))
				{
				case 1:
					current_logged_user.view_profile();
					break;
				case 2:
					books.add_book();
					break;
				case 3:
					run = false;
					break;
				}
			}
		}
		else
		{
			std::cout << "User view\n\n";
			choices.clear();
			choices.push_back("View Profile");
			choices.push_back("List & Select from My Reading History");
			choices.push_back("List & Select from availabel Books");
			choices.push_back("Logout");

			bool run = true;
			while (run)
			{
				menu(choices);
				switch (read_choice(choices.size()))
				{
				case 1:
					current_logged_user.view_profile();
					break;
				case 2:
					if (current_logged_user.get_sessions().size() == 0)
					{
						std::cout << "No Current History...\n\n";
						continue;
					}
					current_logged_user.add_sessions(books.select_from_reading_history(current_logged_user.get_sessions()));
					users.update_users(current_logged_user);
					break;
				case 3:
					current_logged_user.add_sessions(books.list_select_available_books());
					break;
				case 4:
					run = false;
					break;
				}
			}
		}
	}
};

int main(void)
{
	online_book_reader system;
	bool master = true;

	while (master)
	{
		system.run(master);
	}
	
	return 0;
}