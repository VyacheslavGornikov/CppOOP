#include <iostream>

class Point {
    double x {0}, y{0};
public:
    Point(double x = 0, double y = 0) : x(x), y(y)
        { }
    void get_coords(double& x, double& y) const { x = this->x; y = this->y;}
};

class Vector {
    int x {0}, y{0};
public:
    Vector(int x = 0, int y = 0) : x(x), y(y)
        { }
    void get_coords(int& x, int& y) const { x = this->x; y = this->y;}
};

// здесь объявляйте функцию
template <typename T, typename Coord_type = double>
Coord_type sum_coords(const T& obj)
{
    Coord_type x, y;
    obj.get_coords(x, y);
    return x + y;
}

int main()
{
    // здесь продолжайте функцию main
    Point pt(10.5, -4.7);
    Vector vec(132, 55);
    double sm1 = sum_coords(pt);
    int sm2 = sum_coords<Vector, int>(vec);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}