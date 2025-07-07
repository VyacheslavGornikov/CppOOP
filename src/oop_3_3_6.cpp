#include <iostream>
#include <string>

class BankAccount
{
    std::string fio; // владелец счета
    long volume_rub {0}; // объем средств в рублях
public:
    BankAccount(std::string name = "", long rubles = 0) : fio(name), volume_rub(rubles)
    {}
    const std::string& get_fio() const { return fio; } // возвращает значение поля fio
    long get_volume_rub() const { return volume_rub; } // возвращает значение поля volume_rub
    const BankAccount& operator = (long rubles)
    {
        volume_rub = rubles;
        return *this;
    }
};

int main(void)
{
    BankAccount a1;
    a1 = 512000;
    std::cout << a1.get_volume_rub();
}


