#include <iostream>
#include <string>

struct BankAccount {
    std::string fio; // ФИО счета
    long volume {0}; // объем средств на счете

    BankAccount() = default;
    BankAccount(const std::string& fio, long vol) : fio(fio), volume(vol)
        { }
    const long& operator+= (const long& vol)
    {
        volume += vol;
        return volume;
    }

    const long& operator-= (const long& vol)
    {
        volume -= vol;
        return volume;
    }

    const long& operator*= (const double& vol)
    {
        volume *= vol;
        return volume;
    }

    const long& operator/= (const double& vol)
    {
        if (vol != 0) volume /= vol;
        return volume;
    }

    const long& operator%= (const long& vol)
    {
        if (vol != 0) volume %= vol;
        return volume;
    }
};

class Bank {
    enum { max_accounts = 100 }; // максимальное количество счетов
    BankAccount* acs {nullptr}; // массив из счетов
    size_t count {0}; // текущее количество счетов
public:
    Bank()
    {
        acs = new BankAccount[max_accounts];
    }
    Bank(BankAccount* lst, size_t size)
    {
        count = (size > max_accounts) ? max_accounts : size;

        acs = new BankAccount[max_accounts];
        for(size_t i = 0; i < count; ++i)
            acs[i] = lst[i];
    }
    const BankAccount* get_accounts() const { return acs; } // возвращает массив acs
    size_t get_count() const { return count; } // возвращает значение поля count

    const Bank& operator= (const Bank& other)
    {
        if (this == &other) return other;

        delete[] acs;
        count = other.count;
        acs = new BankAccount[count];
        for (size_t i = 0; i < count; i++)
            acs[i] = other.acs[i];
        return *this;
    }

    const Bank& operator+= (const BankAccount& acc)
    {
        if (count + 1 <= max_accounts) acs[count++] = acc;
        return *this;
    }

    Bank operator+ (const BankAccount& acc)
    {
        Bank temp(acs, count);
        temp += acc;
        return temp;
    }

    ~Bank() { delete[] acs; }
};

int main(void)
{
    // здесь продолжайте функцию main
    // Bank balbank;
    // BankAccount ac("Sergey", 4320405);
    // balbank += ac; // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts
    // for (size_t i = 0; i < balbank.get_count(); i++)
    // {
    //     std::cout << balbank.get_accounts()[i].fio << " : "
    //     << balbank.get_accounts()[i].volume << std::endl;
    // }

    // std::cout << "***sep***" << std::endl;

    // balbank = balbank + ac; // добавляет в конец массива acs счет ac, если не превышено максимальное значение max_accounts
    // for (size_t i = 0; i < balbank.get_count(); i++)
    // {
    //     std::cout << balbank.get_accounts()[i].fio << " : "
    //     << balbank.get_accounts()[i].volume << std::endl;
    // }
    // std::cout << "***ac***" << std::endl;
    // ac += 1000; // добавление на счет средств: volume += 1000; fio остается без изменений
    // std::cout << ac.fio << " : " << ac.volume << std::endl;

    // ac -= 1000; // списание со счета средств: volume -= 1000; fio остается без изменений
    // std::cout << ac.fio << " : " << ac.volume << std::endl;

    // ac *= 1.5; // увеличение средств на счете в 1.5 раза с отбрасыванием дробной части: volume *= 1.5; fio остается без изменений
    // std::cout << ac.fio << " : " << ac.volume << std::endl;

    // ac /= 2; // уменьшение средств на счете в 2 раза с отбрасыванием дробной части: volume /= 2; fio остается без изменений
    // std::cout << ac.fio << " : " << ac.volume << std::endl;

    // ac %= 4; // вычисление целого остатка от деления: volume %= 4; fio остается без изменений
    // std::cout << ac.fio << " : " << ac.volume << std::endl;

    // Bank open_b;
    // open_b = balbank; // копирование счетов
    // for (size_t i = 0; i < open_b.get_count(); i++)
    // {
    //     std::cout << open_b.get_accounts()[i].fio << " : "
    //     << open_b.get_accounts()[i].volume << std::endl;
    // }
    BankAccount accs[4] =
    {
        {"А. Дзюба", 43056},
        {"П. Гагарина", 1335395},
        {"О. Бузова", 0},
        {"Тимати", -546}
    };
    Bank my_bank(accs, sizeof(accs) / sizeof(accs[0]));
    for (size_t i = 0; i < my_bank.get_count(); i++)
    {
        std::cout << my_bank.get_accounts()[i].fio << " : "
        << my_bank.get_accounts()[i].volume << std::endl;
    }
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}