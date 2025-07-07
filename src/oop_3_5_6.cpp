#include <iostream>

// здесь объявляйте класс
class Line
{
    short x0 {0}, y0 {0}, x1 {0}, y1 {0};
    int color {0};
public:
    Line() = default;
    Line(short x0, short y0, short x1, short y1) : x0(x0), y0(y0), x1(x1), y1(y1)
    {}
    const Line& operator= (const Line& other)
    {
        x0 = other.x0; y0 = other.y0; x1 = other.x1; y1 = other.y1;
        return *this;
    }
    Line operator+ (const Line& other)
    {
        return Line(x0 + other.x0, y0 + other.y0, x1 + other.x1, y1 + other.y1);
    }

    const Line& operator+= (const Line& right)
    {
        x0 += right.x0; y0 += right.y0; x1 += right.x1; y1 += right.y1;
        return *this;
    }

    const Line& operator-= (const Line& right)
    {
        x0 -= right.x0; y0 -= right.y0; x1 -= right.x1; y1 -= right.y1;
        return *this;
    }

    const Line& operator*= (const Line& right)
    {
        x0 *= right.x0; y0 *= right.y0; x1 *= right.x1; y1 *= right.y1;
        return *this;
    }

    int get_color() const { return color; } // возвращает значение поля color
    void get_coords(short& x0, short& y0, short& x1, short& y1) const
    { x0 = this->x0; y0 = this->y0; x1 = this->x1; y1 = this->y1; } // возвращает значения соответствующих полей
    void set_coords(short x0, short y0, short x1, short y1)
    { this->x0 = x0; this->y0 = y0; this->x1 = x1; this->y1 = y1; } // заносит переданные значения в соответствующие поля
    void set_color(int color) { this->color = color; } // заносит переданное значение в поле color
};

int main(void)
{   short x0, y0, x1, y1;
    Line ln_1, ln_2(1, 2, 3, 4);
    ln_1 = ln_2; // копирование только координат x0, y0, x1, y1 (поле color не копируется)
    ln_1.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    Line ln_new(1, 1, 2, 2);
    ln_new += ln_1; // суммирование только для координат для объекта ln_new (поле color без изменений)
    ln_new.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    ln_1 -= ln_2; // вычитание только для координат для объекта ln_1 (поле color без изменений)
    ln_1.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    ln_new *= ln_2; // умножение только для координат для объекта ln_new (поле color без изменений)
    ln_new.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    Line res = ln_new + ln_2; // сложение соответствующих координат объектов ln_new, ln_2 и присваивание результата объекту res
    res.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;
    return 0;
}



