#include <iostream>

class BottleWater
{
    enum {max_volume = 640}; // максимальный объем воды
    short volume {0}; // объем воды в бутылке
    enum type_assign {
        iadd_operator,
        idif_operator,
        imul_operator,
        idiv_operator
    };
    short _assign_operator (short right, type_assign operation);
    const BottleWater& _assign_operator (const BottleWater& other,
                                         type_assign operation);
public:
    BottleWater(short volume = 0) : volume(volume)
        { }

    short get_volume() const { return volume; }

    BottleWater operator+ (const BottleWater& other)
    {
        int vol = 0;
        if (this == &other) return other;
        vol = volume + other.volume > max_volume ?
              max_volume : volume + other.volume;

        return BottleWater(vol);
    }

    short operator+= (short right)
    { return _assign_operator(right, iadd_operator); }

    const BottleWater& operator+= (const BottleWater& other)
    { return _assign_operator(other, iadd_operator); }

    short operator-= (short right)
    { return _assign_operator(right, idif_operator); }

    const BottleWater& operator-= (const BottleWater& other)
    { return _assign_operator(other, idif_operator); }

    short operator*= (short right)
    { return _assign_operator(right, imul_operator); }

    const BottleWater& operator*= (const BottleWater& other)
    { return _assign_operator(other, imul_operator); }

    short operator/= (short right)
    { return _assign_operator(right, idiv_operator); }

    const BottleWater& operator/= (const BottleWater& other)
    { return _assign_operator(other, idiv_operator); }
};

short BottleWater::_assign_operator (short right, type_assign operation)
{
    if (right < 0) return volume;

    switch (operation)
    {
        case iadd_operator:
            volume + right > max_volume ? volume = max_volume : volume += right;
            break;
        case idif_operator:
            volume - right < 0 ? volume = 0 : volume -= right;
            break;
        case imul_operator:
            volume * right > max_volume ? volume = max_volume : volume *= right;
            break;
        case idiv_operator:
            if (right != 0) volume /= right;
            break;
        default:
            break;
    }
    return volume;
}

const BottleWater& BottleWater::_assign_operator (const BottleWater& other,
                                                  type_assign operation)
{
    switch (operation)
    {
        case iadd_operator:
            this->volume = volume + other.volume > max_volume ?
                          max_volume : volume + other.volume;
            break;
        case idif_operator:
            this->volume = volume - other.volume < 0 ?
                          0 : volume - other.volume;
            break;
        case imul_operator:
            this->volume = volume * other.volume > max_volume ?
                          max_volume : volume * other.volume;
            break;
        case idiv_operator:
            if (other.volume != 0) this->volume /= other.volume;
            break;
        default:
            break;
    }
    return *this;
}

int main(void)
{
    // здесь продолжайте функцию main
    BottleWater b1(10), b2(100);
    BottleWater res_1 = b1 + b2; // res_1: volume = 110

    std::cout << res_1.get_volume() << std::endl;
    b1 += 100; // volume += 100
    std::cout << b1.get_volume() << std::endl;

    b1 -= 20; // volume -= 20
    std::cout << b1.get_volume() << std::endl;

    b1 *= 2; // volume *= 2
    std::cout << b1.get_volume() << std::endl;

    b1 /= 4; // volume /= 4
    std::cout << b1.get_volume() << std::endl;


    b1 += b2; // b1.volume += b2.volume
    std::cout << b1.get_volume() << std::endl;

    b1 -= b2; // b1.volume -= b2.volume
    std::cout << b1.get_volume() << std::endl;

    b1 *= b2; // b1.volume *= b2.volume
    std::cout << b1.get_volume() << std::endl;

    b1 /= b2; // b1.volume /= b2.volume
    std::cout << b1.get_volume() << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)
    BottleWater bw1(40), bw2(200);
    BottleWater res = bw1 + bw2;
    std::cout << res.get_volume() << std::endl;
    return 0;
}