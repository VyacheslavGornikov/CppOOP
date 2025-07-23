#include <iostream>
#include <iomanip>

class FunctionInterface {
public:
    virtual double func(double arg) { return 0; }
    virtual double operator()(double arg) { return 0; }
    virtual ~FunctionInterface() = default;
};

class LinearFunction : public FunctionInterface {
    double k {0.0}; // угловой коэффициент
    double b {0.0}; // смещение
public:
    LinearFunction(double k, double b) : k(k), b(b)
    {}
    virtual double func(double arg) { return k * arg + b; } // возвращает значение линейной функции f(arg) = k*arg+b для аргумента arg
    virtual double operator()(double arg) { return k * arg + b; }// то же самое, только через оператор ()
};

class ReluFunction : public FunctionInterface {
public:
    virtual double func(double arg) { return arg > 0 ? arg : 0; } // возвращает значение функции f(arg) = arg, arg > 0, иначе 0
    virtual double operator()(double arg) { return arg > 0 ? arg : 0; } // то же самое, только через оператор ()
};

int main(void)
{
    // здесь продолжайте функцию main
    FunctionInterface* funcs[3] {nullptr};
    funcs[0] = new LinearFunction(0.5, 0);
    funcs[1] = new LinearFunction(1.2, -5.4);
    funcs[2] = new ReluFunction;

    double value;
    std::cin >> value;
    size_t arr_size = sizeof(funcs) / sizeof(funcs[0]);
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < arr_size; i++)
    {
        std::cout << funcs[i]->func(value);
        if (i != arr_size - 1) std::cout << " ";
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    // здесь освобождайте память
    for (size_t i = 0; i < arr_size; i++)
        delete funcs[i];
    return 0;
}