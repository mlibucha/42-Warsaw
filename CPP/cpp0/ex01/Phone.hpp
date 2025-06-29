#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact() {}
	
	void setFirstName(const std::string& name) { firstName = name; }
	void setLastName(const std::string& name) { lastName = name; }
	void setNickname(const std::string& name) { nickname = name; }
	void setPhoneNumber(const std::string& number) { phoneNumber = number; }
	void setDarkestSecret(const std::string& secret) { darkestSecret = secret; }

	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }
	std::string getNickname() const { return nickname; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getDarkestSecret() const { return darkestSecret; }

	void displayContact() const {
		std::cout << "First name: " << firstName << std::endl;
		std::cout << "Last name: " << lastName << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Phone number: " << phoneNumber << std::endl;
		std::cout << "Darkest secret: " << darkestSecret << std::endl;
	}
};


class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;
	int oldestContact;

	std::string truncateString(const std::string& str) const {
		if (str.length() > 10)
			return str.substr(0, 9) + ".";
		return str;
	}

public:
	PhoneBook() : contactCount(0), oldestContact(0) {}
	void addContact();
    void searchContacts() const;
};