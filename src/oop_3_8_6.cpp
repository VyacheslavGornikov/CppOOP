#include <iostream>

// здесь объявляйте класс
class ValueDouble
{
    double value {0.0};
public:
    ValueDouble (double value = 0.0) : value(value)
    {}
    double get_value() const { return value; }
    friend ValueDouble operator+ (const ValueDouble& left, const ValueDouble& right);
};

ValueDouble operator+ (const ValueDouble& left, const ValueDouble& right)
{
    return ValueDouble (left.value + right.value);
}

int main()
{
    // здесь продолжайте функцию main
    // ValueDouble d1(1.2), d2(5.43);
    // ValueDouble res_1 = d1 + d2; // value = 6.63
    // ValueDouble res_2 = d1 + 4.0; // dist = 5.2
    // ValueDouble res_3 = 0.3 + d2; // dist = 5.73
    // std::cout << res_1.get_value() << " " << res_2.get_value() << " " <<
    // res_3.get_value() << std::endl;
    ValueDouble val(8.7);
    ValueDouble& lnk_vd = val;
    ValueDouble&& lnk_r_vd = std::move(val);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}