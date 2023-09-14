#include"api.h"

int read_choice(int high, int low)
{
	int choice;
	std::cout << "\nEnter number in range 1 - " << high << ": ";
	std::cin >> choice;

	if (choice<low || choice>high)
	{
		std::cout << "Invalid choice...Try Again!\n";
		return read_choice(high, low);
	}
	return choice;
}
void menu(std::vector<std::string> choices)
{
	for (int i = 0; i < choices.size(); i++)
	{
		std::cout << "\t" << i + 1 << ": " << choices[i] << "\n";
	}
}