#include <iostream>
#include <string>

// здесь объявляйте класс
class Distance
{
    int dist {0}; // дистанция
public:
    Distance(int distance = 0) : dist(distance)
    {}
    const Distance& operator= (const Distance& other)
    {
        if (this == &other) return other;
        dist = other.dist;
        return *this;
    }

    const Distance& operator+= (int distance) { dist += distance; return *this; }
    const Distance& operator-= (int distance) { dist -= distance; return *this; }
    const Distance& operator*= (int distance) { dist *= distance; return *this; }
    const Distance& operator/= (int distance)
    {
        if(distance == 0) return *this;
        dist /= distance;
        return *this;
    }
    int operator () () { return dist; }
};

int main()
{
    // здесь продолжайте функцию main
    // Distance d1 = 100;
    // d1 += 50; // dist = 150
    // std::cout << d1() << std::endl;
    // Distance d2 = d1 += 10; // dist в d1 и d2 равны 150+10 = 160
    // std::cout << d1() << " " << d2() << std::endl;
    // Distance res = d2 -= 100; // dist = 60
    // std::cout << res() << " " << d2() << std::endl;
    // Distance sp = d1 *= 5;
    // std::cout << sp() << " " << d1() << std::endl;
    // Distance ep = d1 /= 7;
    // std::cout << ep() << " " << d1() << std::endl;
    //int res = d1(); // возвращает значение поля dist
    Distance d(547);
    //Distance& lnk_d = d;
    Distance&& lnk_r_d = std::move(d);
    lnk_r_d += 100;
    std::cout << lnk_r_d() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}