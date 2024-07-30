#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contacts_count(0) {
}

PhoneBook::~PhoneBook() {
}

std::string get_non_empty_input(const std::string &prompt) {
	std::string input;
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty()) {
			break;
		}
		std::cout << RED << "No empty input allowed. Please try again." << RESET << std::endl;
	}
	return input;
}

void PhoneBook::add_contact() {
	Contact contact;

	std::cout << std::endl;
	contact.set_first_name(get_non_empty_input(BLUE "First name: " RESET));
	contact.set_last_name(get_non_empty_input(BLUE "Last name: " RESET));
	contact.set_nickname(get_non_empty_input(BLUE "Nickname: " RESET));
	contact.set_phone_number(get_non_empty_input(BLUE "Phone number: " RESET));
	contact.set_darkest_secret(get_non_empty_input(BLUE "Darkest secret: " RESET));

	if (contact.get_first_name().empty() || contact.get_last_name().empty() ||
	contact.get_nickname().empty() || contact.get_phone_number().empty() ||
	contact.get_darkest_secret().empty()) {
		std::cout << RED << "Error: All fields must be filled. Contact not added." << RESET << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << GREEN << "Contact added" << RESET << std::endl;
	std::cout << std::endl;

	_contacts[_contacts_count % MAX_CONTACTS] = contact;
	_contacts_count++;
}

void PhoneBook::search_contact() const {
	if (_contacts_count == 0) {
		std::cout << RED << "No contacts available" << RESET << std::endl;
		return;
	}

	_print_table_header();
	int i = 0;
	while (i < (_contacts_count < MAX_CONTACTS ? _contacts_count : MAX_CONTACTS)) {
		_print_contact_row(i, _contacts[i]);
		i++;
	}
	_print_table_footer();

	std::string input;
	std::cout << std::endl;
	std::cout << CYAN << "Enter index to show contact details: " << RESET;
	std::getline(std::cin, input);

	try {
		const int index = std::stoi(input);
		if (index >= 0 && index < (_contacts_count < MAX_CONTACTS ? _contacts_count : MAX_CONTACTS)) {
			_contacts[index].print_contact();
		} else {
			std::cout << RED << "Invalid index" << RESET << std::endl;
		}
	} catch (const std::invalid_argument &) {
		std::cout << RED << "Invalid input: not a number" << RESET << std::endl;
	} catch (const std::out_of_range &) {
		std::cout << RED << "Invalid input: number out of range" << RESET << std::endl;
	}
}

void PhoneBook::add_test_contacts() {
	_contacts[0] = Contact("THIS IS A VERY LONG NAME", "Doe", "jdoe", "1234567890", "I am John Doe");
	_contacts[1] = Contact("Jane", "Doe", "jadoe", "0987654321", "I am Jane Doe");
	_contacts[2] = Contact("Alice", "Smith", "asmith", "1234567890", "I am Alice Smith");
	_contacts[3] = Contact("Bob", "Smith", "bsmith", "0987654321", "I am Bob Smith");
	_contacts[4] = Contact("Charlie", "Brown", "cbrown", "1234567890", "I am Charlie Brown");
	_contacts[5] = Contact("Charlie", "Brown", "cbrown", "1234567890", "I am Charlie Brown");
	_contacts[6] = Contact("Charlie", "Brown", "cbrown", "1234567890", "I am Charlie Brown");
	_contacts[7] = Contact("Charlie", "Brown", "cbrown", "1234567890", "I am Charlie Brown");
	_contacts_count = MAX_CONTACTS;
}

void PhoneBook::_print_table_header() {
	std::cout << YELLOW << "___________________________________________" << RESET << std::endl;
	std::cout << YELLOW << "     index|first name| last name|  nickname" << RESET << std::endl;
}

void PhoneBook::_print_table_footer() {
	std::cout << YELLOW << "___________________________________________" << RESET << std::endl;
}

void PhoneBook::_print_contact_row(int index, const Contact &contact) {
	const char* colors[] = {CYAN, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET};
	const int num_colors = sizeof(colors) / sizeof(colors[0]);
	const char* color = colors[index % num_colors];

	std::cout << color << std::setw(10) << std::right << index << "|";

	std::string first_name = contact.get_first_name();
	if (first_name.length() > 10) {
		first_name = first_name.substr(0, 9) + ".";
	}
	std::cout << std::setw(10) << std::right << first_name << "|";

	std::string last_name = contact.get_last_name();
	if (last_name.length() > 10) {
		last_name = last_name.substr(0, 9) + ".";
	}
	std::cout << std::setw(10) << std::right << last_name << "|";

	std::string nickname = contact.get_nickname();
	if (nickname.length() > 10) {
		nickname = nickname.substr(0, 9) + ".";
	}
	std::cout << std::setw(10) << std::right << nickname << RESET << std::endl;
}
