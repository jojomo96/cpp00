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

private:
	Contact _contacts[8];
	int _contacts_count;

	static void _print_table_header();

	static void _print_contact_row(int index, const Contact &contact);
};
