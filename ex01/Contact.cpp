#include "Contact.hpp"

#include <iomanip>

Contact::Contact() {
}

Contact::~Contact() {
}

Contact::Contact(const std::string &first_name, const std::string &last_name, const std::string &nickname,
                 const std::string &phone_number, const std::string &darkest_secret) : _first_name(first_name),
	_last_name(last_name), _nickname(nickname), _phone_number(phone_number), _darkest_secret(darkest_secret) {
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
	std::cout << "	-------- Contact --------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(18) << std::left << "	First name: " << _first_name << std::endl;
	std::cout << std::setw(18) << std::left << "	Last name: " << _last_name << std::endl;
	std::cout << std::setw(18) << std::left << "	Nickname: " << _nickname << std::endl;
	std::cout << std::setw(18) << std::left << "	Phone number: " << _phone_number << std::endl;
	std::cout << std::setw(18) << std::left << "	Darkest secret: " << _darkest_secret << std::endl;
	std::cout << std::endl;
	std::cout << "	-------------------------" << std::endl;
	std::cout << std::endl;
}
