#pragma once

#include <iostream>
#include <iomanip>

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();

	~PhoneBook();

	void add_contact();

	void search_contact() const;

	void add_test_contacts();

	static void read_next_line(std::string &input);

private:
	static const int MAX_CONTACTS = 8;
	Contact _contacts[MAX_CONTACTS];
	int _contacts_count;

	static void _print_table_header();

	static void _print_table_footer();

	static void _print_contact_row(int index, const Contact &contact);
};
