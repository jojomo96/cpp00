#include "Contact.hpp"

#include <iomanip>

Contact::Contact() {
}

Contact::~Contact() {
}

Contact::Contact(const char * first_name, const char * last_name, const char * nickname,
                 const char * phone_number, const char * darkest_secret) {
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}

std::string Contact::get_first_name() const {
	return _first_name;
}

void Contact::set_first_name(const std::string &first_name) {
	_first_name = first_name;
}

std::string Contact::get_last_name() const {
	return _last_name;
}

void Contact::set_last_name(const std::string &last_name) {
	_last_name = last_name;
}

std::string Contact::get_nickname() const {
	return _nickname;
}

void Contact::set_nickname(const std::string &nickname) {
	_nickname = nickname;
}

std::string Contact::get_phone_number() const {
	return _phone_number;
}

void Contact::set_phone_number(const std::string &phone_number) {
	_phone_number = phone_number;
}

std::string Contact::get_darkest_secret() const {
	return _darkest_secret;
}

void Contact::set_darkest_secret(const std::string &darkest_secret) {
	_darkest_secret = darkest_secret;
}

void Contact::print_contact() const {
	std::cout << std::endl;
	std::cout << MAGENTA << "\t-------- Contact --------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN << std::setw(18) << std::left << "\tFirst name: " << RESET << _first_name << std::endl;
	std::cout << CYAN << std::setw(18) << std::left << "\tLast name: " << RESET << _last_name << std::endl;
	std::cout << CYAN << std::setw(18) << std::left << "\tNickname: " << RESET << _nickname << std::endl;
	std::cout << CYAN << std::setw(18) << std::left << "\tPhone number: " << RESET << _phone_number << std::endl;
	std::cout << CYAN << std::setw(18) << std::left << "\tDarkest secret: " << RESET << _darkest_secret << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA << "\t-------------------------" << RESET << std::endl;
	std::cout << std::endl;
}
