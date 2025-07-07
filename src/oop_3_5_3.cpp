#include <iostream>

class Distance {
    int dist {0};
public:
    Distance(int d) : dist(d)
        { }
    int operator+= (int right) { dist += right; return dist; }
    int operator-= (int right) { dist -= right; return dist; }
    int operator*= (int right) { dist *= right; return dist; }
    int operator/= (int right) { dist /= right; return dist; }

    const Distance& operator= (const Distance& other)
    {
        if (this == &other) return other;
        this->dist = other.dist;
        return *this;
    }
    operator int() const { return dist; }
    int get_distance() const { return dist; }
};

int main(void)
{
    Distance d1 = 100;
    d1 += 50; // dist = 150
    std::cout << d1.get_distance() << std::endl;
    Distance d2 = d1 += 10; // dist в d1 и d2 равны 150+10 = 160
    std::cout << d2.get_distance() << std::endl;
    Distance res = d2 -= 100; // dist = 60
    std::cout << res.get_distance() << std::endl;
    Distance sp = d1 *= 5;
    std::cout << sp.get_distance() << std::endl;
    Distance ep = d1 /= 7;
    std::cout << ep.get_distance() << std::endl;
    int resd = sp; // возвращает значение поля dist
    std::cout << resd << std::endl;
    return EXIT_SUCCESS;
}