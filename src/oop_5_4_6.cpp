#include <iostream>
#include <string>
#include <cctype>

class ExceptionConvert {
    std::string msg;
public:
    ExceptionConvert(const std::string& msg) : msg(msg) {}
    const std::string& to_msg() const { return msg; }
};

class ConvertToInt {
    int number{0};
    bool is_err{false};
public:
    ConvertToInt() = default;

    int operator()(const char* str_to_int) {
        is_err = false;
        bool has_digit = false;
        bool has_dot = false;

        // Проверка каждого символа
        for (int i = 0; str_to_int[i] != '\0'; ++i) {
            char c = str_to_int[i];

            if (c == '-' || c == '+') {
                // Знак может быть только первым символом
                if (i != 0) {
                    is_err = true;
                    throw ExceptionConvert("Conversion error");
                }
            }
            else if (c == '.') {
                // Точка может быть только одна
                if (has_dot) {
                    is_err = true;
                    throw ExceptionConvert("Conversion error");
                }
                has_dot = true;
            }
            else if (!std::isdigit(c)) {
                // Все остальные символы должны быть цифрами
                is_err = true;
                throw ExceptionConvert("Conversion error");
            }
            else {
                has_digit = true;
            }
        }

        // Если нет ни одной цифры - ошибка
        if (!has_digit) {
            is_err = true;
            throw ExceptionConvert("Conversion error");
        }

        // Конвертация с помощью atoi (она автоматически остановится на точке)
        number = std::atoi(str_to_int);
        return number;
    }

    bool is_error() const { return is_err; }
    operator int() const { return number; }
};

// int operator()(const char* str)     // функтор
//     {
//         // То есть, любой нецифровой символ, кроме '+', '-', '.', приводит к ошибке конвертации строки в число.
//         const char* x {"+-.0123456789"};    // если есть любой символ кроме этих, то выбрасываем исключение
//         bool res{false};
//         for(int i=0; str[i] != 0; ++i) {
//             for(int j=0; x[j] != 0; ++j) {
//                 res = res || (str[i] == x[j]);
//             }
//             if(!res)
//                 throw ExceptionConvert("Conversion error");
//             res = false;
//         }

//         return atoi(str);
//     }

int main() {
    std::string digit;
    getline(std::cin, digit);
    const char* str = digit.c_str();

    ConvertToInt str_to_int;

    try {
        int res = str_to_int(str);
        std::cout << res;
    }
    catch (const ExceptionConvert& e) {
        std::cout << e.to_msg();
    }

    //__ASSERT_TESTS__

    return 0;
}