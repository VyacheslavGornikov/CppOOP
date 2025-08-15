#include <iostream>

// здесь объявляйте классы
class Wallet
{
    enum {wallet_limit = 1000000}; // лимит денег в кошельке
    long volume {0}; // количество денег в кошельке
    bool is_valid(long volume)
    {
        return volume < 0 || volume > wallet_limit - 1 ? false : true;
    }
public:
    Wallet(long volume = 0)
    {
        if (is_valid(volume))
            this->volume = volume;
        else
            throw "Volume is out of bounds.";
    }
    long get_volume() const { return volume; } // возвращает значение поля volume

    void operator+= (long value)
    {
        if (!is_valid(this->volume + value))
            throw "Volume is out of bounds.";
        this->volume += value;
    }
    void operator-= (long value)
    {
        if (!is_valid(this->volume - value))
            throw "Volume is out of bounds.";
        this->volume -= value;
    }
    friend Wallet operator+ (const Wallet& left ,const Wallet& right)
    {
        return Wallet(left.volume + right.volume);
    }

};

int main(void)
{
    // здесь продолжайте функцию main
    try
    {
        Wallet wl(500);
    }
    catch (const char* ex)
    {
        std::cout << ex;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}