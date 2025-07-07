#include <iostream>

// здесь объявляйте класс
class Distance
{
    long dist {0}; // дистанция в миллиметрах
public:
    Distance(long dist = 0) : dist(dist)
    {}
    friend void set_distance(Distance& dst, long value); // заносит в поле dist объекта dst значение value
    friend long get_distance(const Distance& dst); // возвращает значение поля dist объекта dst
    friend double distance_to_meters(const Distance& dst); // возвращает значение поля dist объекта dst в метрах
    friend Distance operator + (const Distance& left, const Distance& right);
};

void set_distance(Distance& dst, long value) { dst.dist = value; } // заносит в поле dist объекта dst значение value
long get_distance(const Distance& dst) { return dst.dist; } // возвращает значение поля dist объекта dst
double distance_to_meters(const Distance& dst)
{ return (double)dst.dist / 1000.0; } // возвращает значение поля dist объекта dst в метрах
Distance operator + (const Distance& left, const Distance& right)
{ return get_distance(left) + get_distance(right); }

int main(void)
{
    // здесь продолжайте функцию main
    Distance d(783);
    printf("%ld %.2lf", get_distance(d), distance_to_meters(d));

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}