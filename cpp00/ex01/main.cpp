#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

void addContact(Phonebook *phonebook)
{
	Contact 	contact;
	std::string str;

	int count;

	count = phonebook->getCount();
	if(count == 8)
		std::cout << "Table is full!, replace the oldest one ?" << std::endl;
	std::cout << "First name: ";
	if(!(std::getline(std::cin >> std::ws , str)))
		return ;
	contact.setFirstName(str);
	std::cout << "Last name: ";
	if(!(std::getline(std::cin >> std::ws , str)))
		return ;
	contact.setLastName(str);
	std::cout << "Nickname: ";
	if(!(std::getline(std::cin >> std::ws , str)))
		return ;
	contact.setNickName(str);
	std::cout << "Phone number: ";
	if(!(std::getline(std::cin >> std::ws , str)))
		return ;
	contact.setPhoneNumber(str);
	std::cout << "Darkest secret: ";
	if(!(std::getline(std::cin >> std::ws , str)))
		return ;
	contact.setSecret(str);
	phonebook->setContact(contact);
}

std::string truncate(std::string str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void searchContact(Phonebook *phonebook)
{
	int index;
	int count;

	count = phonebook->getCount();
	std::cout << "|──────────|──────────|──────────|──────────|" << std::endl;
	std::cout << "│" << std::setw(10) << std::right << "index";
	std::cout << "│" << std::setw(10) << std::right << "first name";
	std::cout << "│" << std::setw(10) << std::right << "last name";
	std::cout << "│" << std::setw(10) << std::right << "nickname" << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i=0; i < phonebook->getCount(); i++)
	{
		Contact contact;
		contact = phonebook->getContact(i);
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << truncate(contact.getFirstName());
		std::cout << "|" << std::setw(10) << truncate(contact.getLastName());
		std::cout << "|" << std::setw(10) << truncate(contact.getNickName()) << "|" << std::endl;
	}
	std::cout << "|──────────|──────────|──────────|──────────|" << std::endl;
	if (count > 0)
	{
		std::cout << "Please enter an index for relevant information: ";
		while (!(std::cin >> index) || index > count || index < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid. Please enter an index between 1 and " << count << ": ";
		}
		index--;
		Contact contact;
		contact = phonebook->getContact(index);
		std::cout << std::endl;
		std::cout << "First name - " << contact.getFirstName() << std::endl;
		std::cout << "Last name - " << contact.getLastName() << std::endl;
		std::cout << "Nickname - " << contact.getNickName() << std::endl;
		std::cout << "Phone number - " << contact.getPhoneNumber() << std::endl;
		std::cout << "Darkest secret - " << contact.getSecret() << std::endl;
	}
	else{
		std::cout << "Table is empty!" << std::endl;
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	Phonebook phonebook;
	
	while (1)
	{
		std::string command;
		std::cout << "Enter a command: ";
		if(!(std::getline(std::cin, command)))
			break;
		if (command == "ADD")
			addContact(&phonebook);
		else if (command == "SEARCH")
			searchContact(&phonebook);
		else if (command == "EXIT")
			break;
		else
			std::cout << "Inalid" << std::endl;	
	}
	return (0);
}