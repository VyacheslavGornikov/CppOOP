#include <iostream>
#include <string>

// здесь объявляйте классы
template <typename T>
class Validator
{
protected:
    std::string msg_ex; // сообщение исключения
public:
    Validator(const std::string& message) : msg_ex(message) {}
    virtual bool is_valid(T x, bool exception = true) const = 0; // проверка условия для значения x (сама проверка реализуется в дочерних классах)
    virtual ~Validator() = default;
};

template <typename T>
class ValidatorRange : public Validator<T>
{
    T min_value {0}, max_value {0};  // диапазон [min_value; max_value]
public:
    ValidatorRange(const std::string& message, T min_value, T max_value) :
            Validator<T>(message), min_value(min_value), max_value(max_value) {}
    bool is_valid(T x, bool exception = true) const override
    {
        if (x < min_value || x > max_value)
        {
            if (exception)
                throw this->msg_ex;
            return false;
        }
        return true;
    } // возвращает true, если x принадлежит диапазону [min_value; max_value], иначе false
};

int main(void)
{
    // здесь продолжайте функцию main
    ValidatorRange<double> vr ("Value is outside the range [-4.5; 2.5]", -4.5, 2.5);
    try
    {
        double x;
        std::cin >> x;
        vr.is_valid(x);
    }
    catch (const std::string& ex)
    {
        std::cout << ex;
    }
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}