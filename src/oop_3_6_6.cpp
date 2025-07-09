#include <iostream>

class LineDouble
{
    double x0 {0}, y0 {0}, x1 {0}, y1 {0}; // координаты линии
public:
    LineDouble() = default;
    LineDouble(double x0, double y0, double x1, double y1) :
    x0(x0), y0(y0), x1(x1), y1(y1) {}

    void set_coords(double a, double b, double c, double d)
    { x0 = a; y0 = b; x1 = c; y1 = d; } // заносит в поля x0, y0, x1, y1 переданные значения
    void get_coords(double& a, double& b, double& c, double& d) const
    { a = x0; b = y0; c = x1; d = y1; } // возвращает координаты x0, y0, x1, y1

    LineDouble operator+ (const LineDouble& other)
    {
        return LineDouble(x0 + other.x0, y0 + other.y0,
                          x1 + other.x1, y1 + other.y1);
    }

    const LineDouble& operator+= (double value)
    {
        x0 += value; y0 += value; x1 += value; y1 += value;
        return *this;
    }

    const LineDouble& operator-= (double value)
    {
        x0 -= value; y0 -= value; x1 -= value; y1 -= value;
        return *this;
    }

    const LineDouble& operator+= (const LineDouble& right)
    {
        x0 += right.x0; y0 += right.y0; x1 += right.x1; y1 += right.y1;
        return *this;
    }

    const LineDouble& operator-= (const LineDouble& right)
    {
        x0 -= right.x0; y0 -= right.y0; x1 -= right.x1; y1 -= right.y1;
        return *this;
    }

    void operator++ ()
    {
        x0 += 0.1; y0 += 0.1; x1 += 0.1; y1 += 0.1;
    }

    void operator-- ()
    {
        x0 -= 0.1; y0 -= 0.1; x1 -= 0.1; y1 -= 0.1;
    }

    void operator++ (int)
    {
        x0 += 0.1; y0 += 0.1; x1 += 0.1; y1 += 0.1;
    }

    void operator-- (int)
    {
        x0 -= 0.1; y0 -= 0.1; x1 -= 0.1; y1 -= 0.1;
    }
};

int main(void)
{
    double x0, y0, x1, y1;
    LineDouble ln1(1, 2, 3, 4), ln2(10, 20, 30, 40);
    LineDouble ln = ln1 + ln2; // сложение соответствующих координат между собой (объекты ln1, ln2 не меняются)
    ln.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    printf("r_n\n");
    LineDouble r_1 = ln1 += 1.5; // к каждой координате прибавляется значение 1.5
    r_1.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    LineDouble r_2 = ln2 -= 0.1; // от каждой координаты вычитается значение 0.1
    r_2.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    LineDouble r_3 = ln2 += ln1; // сумма соответствующих координат с сохранением результата в объекте ln2
    r_3.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    LineDouble r_4 = ln1 -= ln2; // разность соответствующих координат с сохранением результата в объекте ln1
    r_4.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    printf("ln++\n");
    ln1++; // увеличение каждой координаты на 0.1
    ln1.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    ++ln1; // увеличение каждой координаты на 0.1
    ln1.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    ln2--; // уменьшение каждой координаты на 0.1
    ln2.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    --ln2; // уменьшение каждой координаты на 0.1
    ln2.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;
    return 0;
}