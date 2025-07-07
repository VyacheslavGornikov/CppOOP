#include <iostream>
#include <cmath>

// здесь объявляйте класс
class AbsoluteValue
{
public:
    unsigned long value {0};
    AbsoluteValue() = default;
    AbsoluteValue(long val) : value(abs(val))
    {}
    const AbsoluteValue& operator = (const AbsoluteValue& other)
    {
        if (this == &other) return other;
        value = other.value;
        return *this;
    }
};



int main(void)
{
    // здесь продолжайте функцию main
    AbsoluteValue *ptr_abv = new AbsoluteValue();
    *ptr_abv = -512;
    //std::cout << ptr_abv->get_value() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    delete ptr_abv;
    return 0;
}