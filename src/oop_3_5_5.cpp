#include <iostream>
#include <string>

// здесь объявляйте класс
class BankAccount
{
    std::string fio; // владелец счета
    long volume_rub {0}; // объем средств в рублях
public:
    BankAccount(const std::string& fio) : fio(fio)
    {}
    BankAccount(const std::string& fio, long vol_rub) : fio(fio), volume_rub(vol_rub)
    {}
    const BankAccount& operator= (long vol_rub)
    {
        volume_rub = vol_rub;
        return *this;
    }

    long operator+= (long vol_rub)
    {
        volume_rub += vol_rub;
        return volume_rub;
    }

    long operator-= (long vol_rub)
    {
        volume_rub -= vol_rub;
        return volume_rub;
    }

    const BankAccount& operator+= (const BankAccount& right)
    {
        volume_rub += right.volume_rub;
        return *this;
    }

    const BankAccount& operator-= (const BankAccount& right)
    {
        volume_rub -= right.volume_rub;
        return *this;
    }

    const std::string& get_fio() const { return fio; } // возвращает значение поля fio
    long get_volume_rub() const { return volume_rub; } // возвращает значение поля volume_rub
};

int main(void)
{
    BankAccount a("Старостин"), b("Балакирев"), c("Царев");
    a = 123000; // volume_rub = 123000 (поле fio не меняется)
    b = 12000; b += 8000; // volume_rub = 20000 (поле fio не меняется)
    std::cout << b.get_volume_rub() << std::endl;
    c = 54000; c -= 11000; // volume_rub = 43000 (поле fio не меняется)
    std::cout << c.get_volume_rub() << std::endl;
    a += b; // volume_rub = 123000 + 20000 = 143000 (поле fio не меняется)
    std::cout << a.get_volume_rub() << std::endl;
    a -= c; // volume_rub = 143000 - 43000 = 100000 (поле fio не меняется)
    std::cout << a.get_volume_rub() << std::endl;
    return 0;
}

