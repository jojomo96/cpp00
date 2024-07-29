# include "PhoneBook.hpp"

int main(int argc, char* argv[]) {
	PhoneBook phone_book;

	if (argc > 1 && std::string(argv[1]) == "testdata") {
		phone_book.add_test_contacts();
	}
	std::string input;
	while (true) {
		std::cout << "Enter command: ";
		std::getline(std::cin, input);
		if (input == "EXIT") {
			break;
		} else if (input == "ADD") {
			phone_book.add_contact();
		} else if (input == "SEARCH") {
			phone_book.search_contact();
		} else {
			std::cout << "Invalid command" << std::endl;
		}
	}
	return 0;
}
