#include <iostream>

// здесь объявляйте класс
class Rectangle
{
    int x0 {0}, y0 {0}, x1 {0}, y1 {0};
public:
    Rectangle() = default;
    Rectangle(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1)
    {}
    void get_coords(int& x0, int& y0, int& x1, int& y1) const
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    } // возвращает значение соответствующих полей
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    } // заносит в соответствующие поля переданные значения
    
    Rectangle operator+ (const Rectangle& right)
    {
        int x0_min = std::min(x0, right.x0);
        int y0_min = std::min(y0, right.y0);
        int x1_max = std::max(x1, right.x1);
        int y1_max = std::max(y1, right.y1);
        return Rectangle(x0_min, y0_min, x1_max, y1_max);
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    Rectangle rect_1 (-5, 0, 10, 12);
    Rectangle rect_2 (1, -2, 7, 14);

    Rectangle res = rect_1 + rect_2;
    int x0, y0, x1, y1;
    res.get_coords(x0, y0, x1, y1);
    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}