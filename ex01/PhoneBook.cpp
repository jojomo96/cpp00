#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contacts_count(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add_contact() {
	Contact contact;
	std::string input;
	std::cout << "First name: ";
	std::getline(std::cin, input);
	contact.set_first_name(input);
	std::cout << "Last name: ";
	std::getline(std::cin, input);
	contact.set_last_name(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contact.set_nickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	contact.set_phone_number(input);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	contact.set_darkest_secret(input);
	_contacts[_contacts_count % 8] = contact;
	_contacts_count++;
}

void PhoneBook::search_contact() const {
	if (_contacts_count == 0) {
		std::cout << "No contacts available" << std::endl;
		return;
	}
	_print_table_header();
	for (int i = 0; i < _contacts_count; i++) {
		_print_contact_row(i, _contacts[i]);
	}
	std::string input;
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	const int index = std::stoi(input);
	if (index >= 0 && index < _contacts_count) {
		_contacts[index].print_contact();
	} else {
		std::cout << "Invalid index" << std::endl;
	}
}

void PhoneBook::add_test_contacts() {
	_contacts[0] = Contact("THIS IS A VERY LONG NAME", "Doe", "jdoe", "1234567890", "I am John Doe");
	_contacts[1] = Contact("Jane", "Doe", "jadoe", "0987654321", "I am Jane Doe");
	_contacts[2] = Contact("Alice", "Smith", "asmith", "1234567890", "I am Alice Smith");
	_contacts[3] = Contact("Bob", "Smith", "bsmith", "0987654321", "I am Bob Smith");
	_contacts[4] = Contact("Charlie", "Brown", "cbrown", "1234567890", "I am Charlie Brown");
	_contacts_count = 5;
}

void PhoneBook::_print_table_header() {
	std::cout << "___________________________________________" << std::endl;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
}

void PhoneBook::_print_contact_row(const int index, const Contact &contact) {
	std::cout << std::setw(10) << index;
	std::cout << "|";
	std::cout << std::setw(10) << contact.get_first_name().substr(0, 10);
	std::cout << "|";
	std::cout << std::setw(10) << contact.get_last_name().substr(0, 10);
	std::cout << "|";
	std::cout << std::setw(10) << contact.get_nickname().substr(0, 10);
	std::cout << std::endl;
}
