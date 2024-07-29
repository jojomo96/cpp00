#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

#include <iostream>
#include <ostream>

class Contact {
public:
	Contact();

	~Contact();

	Contact(const std::string &first_name, const std::string &last_name, const std::string &nickname,
	        const std::string &phone_number, const std::string &darkest_secret);

	std::string get_first_name() const;

	void set_first_name(const std::string &first_name);

	std::string get_last_name() const;

	void set_last_name(const std::string &last_name);

	std::string get_nickname() const;

	void set_nickname(const std::string &nickname);

	std::string get_phone_number() const;

	void set_phone_number(const std::string &phone_number);

	std::string get_darkest_secret() const;

	void set_darkest_secret(const std::string &darkest_secret);

	void print_contact() const;

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif //CONTACT_HPP
