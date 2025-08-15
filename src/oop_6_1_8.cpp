#include <iostream>

enum ar_operation {
    ar_sum = 1, // сложение
    ar_sub = 2, // вычитание
    ar_mul = 3 // умножение
};

// здесь объявляйте класс и функцию
class Complex
{
    int re {0}, im {0}; // действительная и мнимая части
public:
    Complex(int re = 0, int im = 0) : re(re), im(im) {}
    Complex operator+ (const Complex& other) { return Complex(re + other.re, im + other.im); }
    Complex operator- (const Complex& other) { return Complex(re - other.re, im - other.im); }
    Complex operator* (const Complex& other)
    {
        return Complex(re * other.re - im * other.im, re * other.im + other.re * im);
    }

    int real() const { return re; } // возвращает значение поля re
    int imag() const { return im; } // возвращает значение поля im
    void set_value(int real, int imag) { re = real; im = imag; } // заносит в поля re и im переданные значения
};

template <typename T>
T calc_data (T a, T b, ar_operation type=ar_sum)
{
    switch (type)
    {
        case ar_sub:
            return a - b;
            break;
        case ar_mul:
            return a * b;
            break;
        default:
            return a + b;
            break;
    }
}

int main()
{
    // здесь продолжайте функцию main
    Complex cmp_1(-5, 23), cmp_2(14, 7);
    auto res_1 = calc_data(cmp_1, cmp_2, ar_sub);
    auto res_2 = calc_data(0.5, 10.4, ar_sum);
    auto res_3 = calc_data(5, -11, ar_mul);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}