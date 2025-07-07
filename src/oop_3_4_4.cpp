#include <iostream>

// здесь объявляйте класс
class Box3D
{
    short a{0}, b{0}, c{0}; // габариты
    class Dimension
    {
        short& dim;
    public:
        Dimension(short& dim) : dim(dim){}
        short operator = (const short& value)
        {
            if (value > 0) dim = value;
            return dim;
        }
        operator short() const { return dim; }
    };
public:
    Box3D() = default;
    Box3D(short a, short b, short c)
    { set_dims(a, b, c); }

    void get_dims(short& a, short& b, short& c) const
    { a = this->a; b = this->b; c = this->c; } // возвращаются значения соответствующих полей

    void set_dims(short a, short b, short c)
    {
        if (a > 0) this->a = a;
        if (b > 0) this->b = b;
        if (c > 0) this->c = c;
    } // в соответствующие поля заносятся переданные значения

    Dimension operator [] (int idx)
    {
        static short dummy = 0;
        if (idx == 0) return Dimension(a);
        if (idx == 1) return Dimension(b);
        if (idx == 2) return Dimension(c);
        return dummy;
    }

    operator int() const { return a * b * c; }
};

int main(void)
{
    Box3D b;
    b[0] = 10; // a = 10
    b[1] = 20; // b = 20
    b[2] = 30; // c = 30
    b[1] = -2;
    //int volume = b; // возвращается объем: a * b * c
    short dim = b[1]; // получение значения габарита по индексу indx
    std::cout << dim << " " << b[1] << std::endl;
}


