# include "PhoneBook.hpp"

int main(int argc, char *argv[]) {
	PhoneBook phone_book;

	std::cout << MAGENTA BOLD << "Welcome to your PhoneBook!" << RESET << std::endl;
	std::cout << "You can use the following commands:" << std::endl;
	std::cout << YELLOW BOLD << "ADD" << RESET << " - Add a new contact" << std::endl;
	std::cout << YELLOW BOLD << "SEARCH" << RESET << " - Search for a contact" << std::endl;
	std::cout << YELLOW BOLD << "EXIT" << RESET << " - Exit the application" << std::endl;

	if (argc > 1 && std::string(argv[1]) == "testdata") {
		phone_book.add_test_contacts();
		std::cout << GREEN << "Test data added to PhoneBook" << RESET << std::endl;
	}

	while (true) {
		std::string input;
		std::cout << BLUE << "Enter command: " << RESET;
		PhoneBook::read_next_line(input);
		if (input == "EXIT") {
			std::cout << GREEN << "Exiting the PhoneBook. Goodbye!" << RESET << std::endl;
			break;
		} else if (input == "ADD") {
			phone_book.add_contact();
		} else if (input == "SEARCH") {
			phone_book.search_contact();
		} else {
			std::cout << RED << "Invalid command. Please try again." << RESET << std::endl;
		}
	}
	return 0;
}
