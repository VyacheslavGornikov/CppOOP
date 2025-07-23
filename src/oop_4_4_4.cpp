#include <iostream>

// здесь объявляйте классы
class Validator
{
public:
    virtual bool is_valid(int x) { return true; } // возвращает значение true
    virtual ~Validator() = default;
};

class PositiveValidator : public Validator
{
public:
    virtual bool is_valid(int x) { return x >= 0 ? true : false; } // возвращает значение true, если x >= 0 и false в противном случае
};

class RangeValidator : public Validator
{
    int left{0}, right{0};
public:
    RangeValidator(int left, int right) : left(left), right(right)
    {}
    virtual bool is_valid(int x) { return x >= left && x <= right ? true : false; } // возвращает значение true, если x в диапазоне [left; right], и false в противном случае
};

int main(void)
{
    // здесь продолжайте функцию main
    Validator* vs[3] {nullptr};
    vs[0] = new PositiveValidator();
    vs[1] = new RangeValidator(-5, 5);
    vs[2] = new RangeValidator(-15, 10);

    int value;
    std::cin >> value;
    size_t arr_size = sizeof(vs) / sizeof(vs[0]);

    for (size_t i = 0; i < arr_size; i++)
    {
        std::cout << vs[i]->is_valid(value);
        if (i != arr_size - 1) std::cout << " ";
    }
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память (если необходимо)
    for (size_t i = 0; i < arr_size; i++)
        delete vs[i];
    return 0;
}