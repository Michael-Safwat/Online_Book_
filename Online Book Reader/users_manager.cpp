#include"users_manager.h"

users_manager::users_manager()
{
	user user;

	user.set_name("Shery");
	user.set_email("sher@gmail.com");
	user.set_username("Sher");
	user.set_password("123");
	user.set_is_admin(false);

	users[user.get_username()] = user;

	user.set_name("Michael");
	user.set_email("mike34@gmail.com");
	user.set_username("Mike");
	user.set_password("123");
	user.set_is_admin(true);

	users[user.get_username()] = user;
}

bool users_manager::login(user& current_logged_user)
{
	std::string username, password;
	std::cout << "Enter username and password: ";
	std::cin >> username >> password;

	if (users.count(username))
	{
		if (users[username].get_password() == password)
		{
			current_logged_user = users[username];
			return true;
		}

		std::cout << "Incorrect username or password\n\n";
		return false;
	}
	std::cout << "There is no user with this credentials\n\n";
	return false;
}
bool users_manager::signup(user& current_logged_user)
{
	std::string str;

	std::cout << "Enter username: ";
	std::cin>>str;

	if (users.count(str))
	{
		std::cout << "Current username in use\n\n";
		return false;
	}
	current_logged_user.set_username(str);

	std::cout << "Enter password: ";
	std::cin.ignore();
	getline(std::cin, str);
	current_logged_user.set_password(str);

	std::cout << "Enter e-mail: ";
	getline(std::cin, str);
	current_logged_user.set_email(str);

	std::cout << "Enter Full Name: ";
	getline(std::cin, str);
	current_logged_user.set_name(str);

	users[current_logged_user.get_username()] = current_logged_user;
	return true;
}

void users_manager::update_users(const user& current_logged_user)
{
	users[current_logged_user.get_username()].set_sessions(current_logged_user.get_sessions());
}