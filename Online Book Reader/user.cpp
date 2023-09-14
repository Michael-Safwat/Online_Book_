#include"user.h"

user::user():is_admin(false)
{

}

const std::string& user::get_username()const
{
	return username;
}
void user::set_username(const std::string& username) 
{
	this->username = username;
}

const std::string& user::get_name()const
{
	return name;
}
void user::set_name(const std::string& name)
{
	this->name = name;
}

const std::string& user::get_password()const
{
	return password;
}
void user::set_password(const std::string& password)
{
	this->password = password;
}

const std::string& user::get_email()const
{
	return email;
}
void user::set_email(const std::string& email)
{
	this->email = email;
}

const std::vector<book>& user::get_sessions()const
{
	return sessions;
}
void user::set_sessions(const std::vector<book>& sessions)
{
	this->sessions = sessions;
}
void user::add_sessions(const book& chosen_book)
{
	sessions.push_back(chosen_book);
}

const bool& user::get_is_admin()const
{
	return is_admin;
}
void user::set_is_admin(bool is_admin)
{
	this->is_admin = is_admin;
}

bool user::login(const std::string& username, const std::string& password)const
{
	if (get_username() == username && get_password() == password)
		return true;
	return false;
}

void user::view_profile()const
{
	std::cout << "Username: " << get_username() << "\n" << "Name: " << get_name() << "\n" << "E-mail: " << get_email() << "\n";
}