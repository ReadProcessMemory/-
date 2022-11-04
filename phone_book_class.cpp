#include "phone_book_class.h"

std::vector<std::string> gay_data; //fr gay_data

phone_book::phone_book(std::ifstream& file)
{
	phone_book_data.clear(); //better performance!
	std::string file_line;
	while (std::getline(file, file_line)) //1 раз!(для разделения)
	{
		//std::ifstream line_of_file(file_line.c_str());//std::to_ifstream? //https://stackoverflow.com/questions/4881210/how-to-convert-a-string-to-a-ifstream
		std::stringstream line_of_file(file_line);	//https://bytes.com/topic/c/answers/638804-i-want-create-std-ifstream-using-std-string
		for (std::string name; std::getline(line_of_file, name, ';');)//2 раз!(для разделения) //https://stackoverflow.com/questions/20739453/using-getline-with-file-input-in-c
		{
			gay_data.push_back(name);
		}
		person new_person;
		new_person.name = gay_data[0];
		new_person.patronymic = gay_data[1];
		new_person.surname = gay_data[2];

		phone_number new_phone_number;
		new_phone_number.city_code = atoi(gay_data[3].c_str()); //https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
		new_phone_number.country_code = atoi(gay_data[4].c_str());
		new_phone_number.extension_number = atoi(gay_data[5].c_str());
		new_phone_number.number = atoi(gay_data[6].c_str());
		gay_data.clear(); //better performance!

		std::pair<person, phone_number> new_main_list(new_person, new_phone_number);
		phone_book_data.push_back(new_main_list);
	}

}

//----------------------get_phone_number----------------------\\

std::pair<std::string, phone_number> phone_book::get_phone_number(std::string surname)
{
	int i = 0;
	phone_number newphone{ 0,0,"" };
	for (auto& [persons, telephone] : phone_book_data)
	{
		if (persons.surname == surname)
		{
			i++;
			newphone = telephone;
		}
	}
	if (i == 1)
	{
		return {"", newphone};
	}
	else
	{
		return {"", newphone };
	}
}

bool phone_book::change_phone_number(const person& newperson, const phone_number& newphone_number)
{
	for (auto& [pperson, pphone_number] : phone_book_data)
	{
		if (pperson == newperson) //gay gay operator!
		{
			pphone_number = newphone_number;
			return true;
		}
	}
	return false;
}

//----------------------sort----------------------\\

void phone_book::sort_by_phone()
{

	std::sort(phone_book_data.begin(), phone_book_data.end(), [](std::pair<person, phone_number>& l, std::pair<person, phone_number>& r) -> bool
	{
		return l.second < r.second;
	});
}

void phone_book::sort_by_name()
{
	std::sort(phone_book_data.begin(), phone_book_data.end(), [](std::pair<person, phone_number>& l, std::pair<person, phone_number>& r) -> bool
	{
		return l.first < r.first;
	});
}

//----------------------operators----------------------\\

bool phone_number::operator==(const phone_number& gay)
{
	return tie(this->country_code, this->city_code, this->number, this->extension_number) == tie(gay.country_code, gay.city_code, gay.number, gay.extension_number);
}

bool person::operator==(const person& gay)
{
	return tie(this->surname, this->name, this->patronymic) == tie(gay.surname, gay.name, gay.patronymic);
}

bool phone_number::operator<(const phone_number& gay)
{
	return tie(this->country_code, this->city_code, this->number, this->extension_number) < tie(gay.country_code, gay.city_code, gay.number, gay.extension_number);
}

bool person::operator<(const person& gay)
{
	return tie(this->surname, this->name, this->patronymic) < tie(gay.surname, gay.name, gay.patronymic);
}

std::ostream& operator<<(std::ostream& num1, const person& p2cperson)
{
	num1 << p2cperson.surname << " " << p2cperson.name;
	if (p2cperson.patronymic != "") 
	{
		num1 << " " << p2cperson.patronymic;
	}
	return num1;
}

std::ostream& operator<<(std::ostream& num1, const phone_number& p2cphone_number)
{
	num1 << "+" << p2cphone_number.city_code << p2cphone_number.country_code << p2cphone_number.number;
	if (p2cphone_number.extension_number)
	{
		num1 << " " << *p2cphone_number.extension_number;
	}
	return num1;
}

std::ostream& operator<<(std::ostream& num1, phone_book& p2cphone_book)
{
	for (const auto& [per, tel] : p2cphone_book.phone_book_data)
	{
		num1 << per << " " << tel << std::endl;
	}
	return num1;
}