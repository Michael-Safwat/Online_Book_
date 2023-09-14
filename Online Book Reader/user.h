#pragma once
#include<string>
#include<iostream>
#include<vector>
#include"book.h"

class user
{
private:
	std::string username;
	std::string name;
	std::string password;
	std::string email;
	std::vector<book> sessions;
	bool is_admin;
	
public:
	user();

	const std::string& get_username()const;
	void set_username(const std::string& username);
	
	const std::string& get_name()const;
	void set_name(const std::string& name);
	
	const std::string& get_password()const;
	void set_password(const std::string& password);
	
	const std::string& get_email()const;
	void set_email(const std::string& email);
	
	const std::vector<book>& get_sessions()const;
	void set_sessions(const std::vector<book>& sessions);
	void add_sessions(const book& chosen_book);

	const bool& get_is_admin()const;
	void set_is_admin(bool is_admin);
	
	bool login(const std::string& username, const std::string& password)const;
	
	void view_profile()const;
};