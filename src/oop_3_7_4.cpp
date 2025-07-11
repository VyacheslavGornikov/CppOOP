#include <iostream>
#include <string>

// здесь объявляйте класс
class ConvertToInt
{
    int number {0};
    bool is_err {false};
public:
    ConvertToInt() = default;

    int operator() (const char* str_to_int)
    {
        is_err = false;
        for (int i = 0; str_to_int[i] != '\0'; i++)
        {
            if (std::isalpha(str_to_int[i]))
            {
                is_err = true;
                number = 0;
                return number;
            }
        }

        number = std::atoi(str_to_int);
        if (number == 0) is_err = true;
        return number;
    }
    bool is_error() const { return is_err; }
    operator int() const { return number; }
};

int main()
{
    // std::string digit;
    // getline(std::cin, digit);

    // const char* str = digit.c_str(); // массив символов char с прочитанной строкой

    ConvertToInt conv_int;

    int res_1 = conv_int("123"); // res_1 = 123
    int res_2 = conv_int("a123"); // res_2 = 0 (ошибка конвертации)
    int res_3 = conv_int("-123"); // res_3 = -123
    int res_4 = conv_int("13b"); // res_4 = 0 (ошибка конвертации)
    int res_5 = conv_int("+17"); // res_5 = 17
    int res_6 = conv_int("1.7"); // res_6 = 1

    std::cout << res_1 << " " << res_2 << " " << res_3 << " " << res_4 << " "
    << res_5 << " " << res_6 << std::endl;
    // здесь продолжайте функцию main

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}