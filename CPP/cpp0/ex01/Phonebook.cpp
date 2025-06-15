#include <iostream>
#include <string>
#include <cctype>


void searchContacts(int amount, std::string contacts[8][5])
{
	if (amount == 0)
	{
		std::cout << "\033[31mNo contacts available.\033[0m" << std::endl;
		return;
	}
	std::cout << "Available contacts:" << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		if (!contacts[i][0].empty())
		{
			std::cout << "Contact #" << i + 1 << ": ";
			for (int j = 0; j < 5; ++j)
			{
				std::cout << contacts[i][j] << (j < 4 ? ", " : "\n");
			}
		}
	}
	std::cout << "Press Enter to continue..." << std::endl;
}

void addContact(int amount, std::string contacts[8][5])
{
	int num = amount % 8;
	if(num == 0 && amount > 0)
		num = 7;
	std::cout << "Adding contact #" << num + 1  << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if (i == 0)
			std::cout << "Enter first name: ";
		else if (i == 1)
			std::cout << "Enter last name: ";
		else if (i == 2)
			std::cout << "Enter nickname: ";
		else if (i == 3)
			std::cout << "Enter address: ";
		else if (i == 4)
			std::cout << "ENTER Darkest Secret: ";
		std::string input;
		std::getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "\033[31mInput cannot be empty. Please try again.\033[0m" << std::endl;
			--i;
			continue;
		}
		else
			contacts[num][i] = input;
	}
	std::cout << "Contact added successfully." << std::endl;
}
int main(int argc, char **argv) 
{
	if(argc != 1)
	{
		std::cout << "Usage: " << argv[0] << std::endl;
		return 1;
	}

	std::cout << "Phonebook application started." << std::endl;
	std::cout << "\033[32mCommands: ADD, SEARCH, EXIT\033[0m" << std::endl;

	std::string contacts[8][5];
	int amount = 0;
	while (1)
	{
		std::string cmd;
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, cmd))
		{
			if (std::cin.eof())
			{
				std::cout  << std::endl << "Exiting due to EOF." << std::endl;
				break;
			}
			std::cin.clear();
			continue;
		}

		if (cmd == "ADD")
		{
			std::cout << "Adding a contact..." << std::endl;
			addContact(amount, contacts);
			amount++;
		}
		else if (cmd == "SEARCH")
		{
			std::cout << "Searching for contacts..." << std::endl;
			searchContacts(amount, contacts);
		}
		else if (cmd == "EXIT")
		{
			std::cout << "Exiting the application." << std::endl;
			break;
		}
		else
			std::cout << "\033[31mUnknown command: " << cmd << ". Please try again.\033[0m" << std::endl;
	}
	return 0;
}