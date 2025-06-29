
#include "Phone.hpp"


void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	while (true) {
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (!input.empty()) {
			newContact.setFirstName(input);
			break;
		}
		std::cout << "\033[31mFirst name cannot be empty. Please try again.\033[0m" << std::endl;
	}
	while (true) {
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (!input.empty()) {
			newContact.setLastName(input);
			break;
		}
		std::cout << "\033[31mLast name cannot be empty. Please try again.\033[0m" << std::endl;
	}
	while (true) {
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (!input.empty()) {
			newContact.setNickname(input);
			break;
		}
		std::cout << "\033[31mNickname cannot be empty. Please try again.\033[0m" << std::endl;
	}
	while (true) {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (!input.empty()) {
			newContact.setPhoneNumber(input);
			break;
		}
		std::cout << "\033[31mPhone number cannot be empty. Please try again.\033[0m" << std::endl;
	}
	while (true) {
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (!input.empty()) {
			newContact.setDarkestSecret(input);
			break;
		}
		std::cout << "\033[31mDarkest secret cannot be empty. Please try again.\033[0m" << std::endl;
	}
	if (contactCount < 8) {
		contacts[contactCount] = newContact;
		contactCount++;
	} else {
		contacts[oldestContact] = newContact;
		oldestContact = (oldestContact + 1) % 8;
	}

	std::cout << "Contact added successfully." << std::endl;
}
void PhoneBook::searchContacts() const {
	if (contactCount == 0) {
		std::cout << "\033[31mNo contacts available.\033[0m" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; ++i) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter contact index to display (1-" << contactCount << "): ";
	std::string input;
	std::getline(std::cin, input);
	std::istringstream iss(input);
	int index;
	if (!(iss >> index) || index < 1 || index > contactCount) {
		std::cout << "\033[31mInvalid index. Please try again.\033[0m" << std::endl;
		return;
	}
	contacts[index - 1].displayContact();
}

int main() {
	PhoneBook phonebook;
	
	std::cout << "Phonebook application started." << std::endl;
	while (true) {
		std::string cmd;
		std::cout << "\033[32mCommands: ADD, SEARCH, EXIT\033[0m" << std::endl;
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, cmd)) {
			if (std::cin.eof()) {
				std::cout << std::endl << "Exiting due to EOF." << std::endl;
				break;
			}
			std::cin.clear();
			continue;
		}

		if (cmd == "ADD") {
			phonebook.addContact();
		} else if (cmd == "SEARCH") {
			phonebook.searchContacts();
		} else if (cmd == "EXIT") {
			std::cout << "Exiting the application." << std::endl;
			break;
		} else {
			std::cout << "\033[31mUnknown command: " << cmd << ". Please try again.\033[0m" << std::endl;
		}
	}

	return 0;
}