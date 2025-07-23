#include <iostream>
#include <string>

// здесь объявляйте класс
class SquareValue
{
    unsigned value {0}; // квадрат числа
public:
    SquareValue(unsigned value = 0) : value (value * value)
    {}
    void operator= (const unsigned& right) { value = right * right; }
    operator unsigned() const { return value; }
    unsigned get_value() const { return value; }
};

int main()
{
    // здесь продолжайте функцию main
    // SquareValue v1; // value = 0
    // SquareValue v2 = 10; // value = 100 (квадрат числа: 10*10 = 100)
    // SquareValue v3 = -50; // value = 2500 (квадрат числа: (-50)*(-50) = 2500)
    // std::cout << v1.get_value() << " " << v2.get_value() << " " <<
    // v3.get_value() << std::endl;

    // v1 = -11; // value = 121 (присваивается квадрат числа)
    // v2 = 7; // value = 49
    // unsigned res = v3; // возвращает значение поля value
    // std::cout << v1.get_value() << " " << v2.get_value() << " " <<
    // res << std::endl;
    SquareValue sqr(9);
    SquareValue& lnk_sq = sqr;
    SquareValue&& lnk_r_sq = std::move(sqr);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}