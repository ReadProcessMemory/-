#include "phone_book_class.h"

/*
Имеется база сотрудников и номеров их телефонов. Требуется написать соответствующие структуры для хранения данных, и заполнить контейнер записями из базы. Затем необходимо реализовать методы обработки данных, а также вывести на экран всю необходимую информацию.

Важно! Имена переменным, классам и функциям давайте осознанные, состоящие из слов на английском языке.
1. Создайте структуру Person с 3 полями: фамилия, имя, отчество. Поле отчество должно быть опционального типа, т.к. не у всех людей есть отчество. Перегрузите оператор вывода данных для этой структуры. Также перегрузите операторы < и == (используйте tie).
2. Создайте структуру PhoneNumber с 4 полями:

· код страны (целое число)
· код города (целое число)
· номер (строка)
· добавочный номер (целое число, опциональный тип)
Для этой структуры перегрузите оператор вывода. Необходимо, чтобы номер телефона выводился в формате: +7(911)1234567 12, где 7 – это номер страны, 911 – номер города, 1234567 – номер, 12 – добавочный номер. Если добавочного номера нет, то его выводить не надо. Также перегрузите операторы < и == (используйте tie)
3. Создайте класс PhoneBook, который будет в контейнере хранить пары: Человек – Номер телефона. Конструктор этого класса должен принимать параметр типа ifstream – поток данных, полученных из файла. В теле конструктора происходит считывание данных из файла и заполнение контейнера. Класс PhoneBook должен содержать перегруженный оператор вывода, для вывода всех данных из контейнера в консоль.

В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы контейнера по фамилии людей в алфавитном порядке. Если фамилии будут одинаковыми, то сортировка должна выполняться по именам, если имена будут одинаковы, то сортировка производится по отчествам. Используйте алгоритмическую функцию sort.
Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по номерам телефонов. Используйте алгоритмическую функцию sort.
Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber. Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке. Если не найден ни один человек с заданной фамилией, то в строке должна быть запись «not found», если было найдено больше одного человека, то в строке должно быть «found more than 1».
Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и, если находит заданного человека в контейнере, то меняет его номер телефона на новый, иначе ничего не делает.
Функция main будет выглядеть так:
int main() {
этого
ifstream file("ХХХ"); // путь к файлу PhoneBook.txt PhoneBook book(file);
cout << book;
cout << "------SortByPhone-------" << endl;
book.SortByPhone();
cout << book;
cout << "------SortByName--------" << endl;
book.SortByName();
cout << book;
cout << "-----GetPhoneNumber-----" << endl;
// лямбда функция, которая принимает фамилию и выводит номер телефона
человека, либо строку с ошибкой
auto print_phone_number = [&book](const string& surname) {
cout << surname << "\t";
auto answer = book.GetPhoneNumber(surname);
if (get<0>(answer).empty())
cout << get<1>(answer);
else
cout << get<0>(answer);
cout << endl;
};
// вызовы лямбды
print_phone_number("Ivanov");
print_phone_number("Petrov");
cout << "----ChangePhoneNumber----" << endl;
book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
PhoneNumber{7, 123, "15344458", nullopt});
book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
PhoneNumber{ 16, 465, "9155448", 13 });
cout << book;
}
*/

int main()
{
    std::ifstream file("book.txt");
    if (!file.is_open())
    {
        std::cout << "file -> gay" << std::endl;
    }
    else
    {
       phone_book book(file);
       std::cout << "------SortByPhone-------" << std::endl;
       book.sort_by_phone();
       std::cout << book;
       std::cout << "------SortByName--------" << std::endl;
       book.sort_by_name();
       std::cout << book;
       std::cout << "-----GetPhoneNumber-----" << std::endl;
       auto print_number = [&book](const std::string& surname) {
           auto phone_by_surname = book.get_phone_number(surname);
           if (std::get<0>(phone_by_surname).empty())
           {
               std::cout << std::get<1>(phone_by_surname) << std::endl;
           }
           else
           {
               std::cout << std::get<0>(phone_by_surname) << std::endl;
           }
       };
       print_number("fff");
       system("pause");
       std::cout << "----ChangePhoneNumber----" << std::endl;
       book.change_phone_number(person{ "Kotov", "Vasilii", "Eliseevich" },
           phone_number{ 7, 123, "15344458", std::nullopt });
       book.change_phone_number(person{ "Mironova", "Margarita", "Vladimirovna" },
           phone_number{ 16, 465, "9155448", 13 });
    }
}
