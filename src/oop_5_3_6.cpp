#include <iostream>
#include <string>

// здесь объявляйте классы
class Validator
{
protected:
    std::string msg_ex; // сообщение исключения
public:
    Validator(const std::string& ex) : msg_ex(ex) {}
    virtual bool is_valid(int x, bool exception = true) const = 0; // проверка условия для значения x (сама проверка реализуется в дочерних классах)
    virtual ~Validator() {}
};

class ValidatorRange : public Validator
{
    int min_value {0}, max_value {0};  // диапазон [min_value; max_value]
public:
    ValidatorRange(const std::string& ex, int min_val, int max_val) :
        Validator(ex), min_value(min_val), max_value(max_val) {}
    virtual bool is_valid(int x, bool exception = true) const override
    {
        if (exception == true)
        {
            if (x < min_value || x > max_value)
                throw msg_ex;
            else
                return true;
        }
        else
        {
            return x < min_value || x > max_value ? false : true;
        }
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    ValidatorRange vr("Value is outside the range [0; 15]", 0, 15);
    int value;
    std::cin >> value;
    try
    {
        vr.is_valid(value);
    }
    catch (const std::string ex)
    {
        std::cout << ex;
    }
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}