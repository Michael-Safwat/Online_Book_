#pragma once
#include<map>
#include"user.h"

class users_manager
{
private:
	std::map<std::string, user> users;

public:
	users_manager();
	
	bool login(user& current_logged_user);
	bool signup(user& current_logged_user);
	void update_users(const user& current_logged_user);
};

