#include <iostream>
#include <memory>

template <typename T>
class GraphInterface {
public:
    virtual void get_coords(T& x0, T& y0, T& x1, T& y1) const = 0;
    virtual void set_coords(T x0, T y0, T x1, T y1) = 0;
    virtual void draw() const = 0;
    virtual ~GraphInterface() { }
};

// здесь объявляйте классы
template <typename T>
class Ellipse : public GraphInterface<T>
{
    T x0 {0}, y0 {0}, x1 {0}, y1 {0};
public:
    Ellipse (T x0 = 0, T y0 = 0, T x1 = 0, T y1 = 0) : x0(x0), y0(y0), x1(x1), y1(y1) {}
    virtual void get_coords(T& x0, T& y0, T& x1, T& y1) const override
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    } // возвращает координаты фигуры
    virtual void set_coords(T x0, T y0, T x1, T y1) override
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    } // задает координаты фигуры
    virtual void draw() const override
    {
        std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << std::endl;
    } // отображает координаты фигуры
};

int main()
{
    // здесь продолжайте функцию main
    std::unique_ptr<Ellipse<short>> eptr1 =
            std::make_unique<Ellipse<short>> (-5, 10, 0, 11);
    std::unique_ptr<Ellipse<short>> eptr2 =
            std::make_unique<Ellipse<short>> (5, 2, -4, -3);
    std::unique_ptr<Ellipse<short>> eptr3 =
            std::make_unique<Ellipse<short>> (1, 5, 10, 22);

    GraphInterface<short>* lst[] =
    {
        eptr1.get(),
        eptr2.get(),
        eptr3.get()
    };

    for (GraphInterface<short>* fig : lst)
    {
        fig->draw();
    }
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}