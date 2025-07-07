#include <iostream>
#include <string>

struct PhoneBookItem {
    std::string fio; // ФИО контакта
    std::string phone_number; // номер телефона

    PhoneBookItem() = default;
    PhoneBookItem(std::string fio, std::string phone_number)
        : fio(fio), phone_number(phone_number)
        { }
};

class PhoneBook {
    enum { max_phone_book = 100 }; // максимальная емкость телефонной книжки
    PhoneBookItem* phone_book {nullptr}; // массив из записей
    size_t count {0}; // количество записей в телефонной книжке
public:
    PhoneBook()
    {
        phone_book = new PhoneBookItem[max_phone_book];
    }
    PhoneBook(PhoneBookItem* lst, size_t size)
    {
        count = (size > max_phone_book) ? max_phone_book : size;

        phone_book = new PhoneBookItem[max_phone_book];
        for(size_t i = 0; i < count; ++i)
            phone_book[i] = lst[i];
    }
    PhoneBook(const PhoneBook& other) : PhoneBook(other.phone_book, other.count)
    {}
    ~PhoneBook() { delete[] phone_book; }

    const PhoneBookItem* get_phone_book() const { return phone_book; } // возвращает массив phone_book
    size_t get_count() const { return count; } // возвращает значение поля count
    bool append(const PhoneBookItem& item)
    {
        if (count == max_phone_book || count < 0) return false;
        phone_book[count] = item;
        count++;
        return true;
    }

    PhoneBook operator + (const PhoneBookItem& other)
    {
        PhoneBook temp(*this);
        temp.append(other);
        return temp;
    }

    const PhoneBook& operator = (const PhoneBook& other)
    {
        if (this == &other) return other;
        delete[] phone_book;
        phone_book = new PhoneBookItem[max_phone_book];
        count = other.count;
        for(size_t i = 0; i < count; ++i)
            phone_book[i] = other.phone_book[i];

        return *this;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    PhoneBook phone_lst;
    phone_lst.append(PhoneBookItem("А. Дзюба", "+71237694401"));
    phone_lst.append(PhoneBookItem("П. Гагарина", "+79234694105"));
    phone_lst.append(PhoneBookItem("О. Бузова", "+79041563055"));
    phone_lst.append(PhoneBookItem("Тимати", "+79121000000"));

    for (size_t i = 0; i < phone_lst.get_count(); i++)
    {
        std::cout << phone_lst.get_phone_book()[i].fio << "\t" <<
        phone_lst.get_phone_book()[i].phone_number << std::endl;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память

    return 0;
}