#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <optional>
#include <variant>
struct person
{
	std::string name;//имя
	std::string surname;//фамилия
	std::string patronymic;//отчество
	bool operator<(const person& gay);
	bool operator==(const person& gay);
	friend std::ostream& operator<<(std::ostream& num1, const person& p2cperson);
};

struct phone_number
{
	int country_code;
	int city_code;
	std::string number; //not string == gay!
	std::optional<int> extension_number;
	bool operator<(const phone_number& gay);
	bool operator==(const phone_number& gay);
	friend std::ostream& operator<<(std::ostream& num1, const phone_number& p2cphone_number);
};

class phone_book
{
	std::vector<std::pair<person, phone_number>> phone_book_data;
public:
	phone_book(std::ifstream& file);
	friend std::ostream& operator<<(std::ostream& num1, phone_book& p2cphone_book);
	void sort_by_phone();
	void sort_by_name();
	std::pair<std::string, phone_number> get_phone_number(std::string surname);
	bool change_phone_number(const person& newperson, const phone_number& newphone_number);
};

