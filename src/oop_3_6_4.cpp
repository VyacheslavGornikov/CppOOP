#include <iostream>

class Clock
{
    unsigned tm {0}; // текущее время
public:
    Clock(unsigned time = 0) : tm(time)
    { if (tm < 0) tm = 0; }
    unsigned get_time() const { return tm; } // возвращает значение поля tm

    Clock operator+ (const Clock& other) { return Clock(tm + other.tm); }
    unsigned operator+= (unsigned time) { return tm += time; }
    unsigned operator-= (unsigned time)
    { return tm = tm < time ? 0 : tm - time; }

    const Clock& operator+= (const Clock& right)
    {
        tm += right.tm;
        return *this;
    }
    const Clock& operator-= (const Clock& right)
    {
        tm = tm < right.tm ? 0 : tm - right.tm;
        return *this;
    }

    unsigned operator++ () { return ++tm; }
    unsigned operator-- ()
    {
        if (tm == 0) return 0;
        return --tm;
    }
    unsigned operator++ (int) { return tm++; }
    unsigned operator-- (int)
    {
        unsigned val = tm;
        if (tm > 0) --tm;
        return val;
    }
    operator unsigned() const { return tm; }
};

int main(void)
{
    Clock cl1(40), cl2(1000);
    Clock res = cl1 + cl2; // cl1.tm + cl2.tm (объекты cl1, cl2 не меняются)
    std::cout << res.get_time() << std::endl;

    Clock r_1 = cl1 += 10; // tm += 10
    std::cout << r_1.get_time() << std::endl;

    Clock r_2 = cl2 -= 10; // tm -= 10
    std::cout << r_2.get_time() << std::endl;

    Clock r_3 = cl2 += cl1; // cl2.tm += cl1.tm
    std::cout << r_3.get_time() << std::endl;

    Clock r_4 = cl1 -= cl2; // cl1.tm -= cl2.tm
    std::cout << r_4.get_time() << std::endl;

    unsigned tm_1 = cl1++; // tm++
    unsigned tm_2 = ++cl1; // ++tm
    unsigned tm_3 = cl1--; // tm--
    unsigned tm_4 = --cl1; // --tm
    std::cout << tm_1 << " " << tm_2 << " " << tm_3 << " " << tm_4 << std::endl;
    return 0;
}