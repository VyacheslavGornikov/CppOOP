#include <iostream>

class IndexError {};

class PointND {
    double* coords {nullptr}; // координаты точки
    size_t dims {0}; // число координат
public:
    PointND() = default;
    PointND(double* cds, size_t len) : dims(len)
    {
        coords = new double[dims];
        for(size_t i = 0;i < dims; ++i)
            coords[i] = cds[i];
    }
    PointND(const PointND& other) : dims(other.dims)
    {
        coords = new double[dims];
        for(size_t i = 0;i < dims; ++i)
            coords[i] = other.coords[i];
    }
    PointND& operator=(const PointND& other)
    {
        if (this != &other)
        {  // Проверка на самоприсваивание
            delete[] coords;    // Освобождаем старые данные

            dims = other.dims;
            coords = new double[dims];
            for (size_t i = 0; i < dims; ++i) {
                coords[i] = other.coords[i];
            }
        }
        return *this;
    }
    double& operator[] (size_t index)
    {
        if (index < 0 || index > dims - 1)
            throw IndexError();
        return coords[index];
    }
    ~PointND() { delete[] coords; }

    size_t get_dims() const { return dims; }
};

int main(void)
{
    // здесь продолжайте функцию main
    double coords[] = {0.1, 0.2, 0.5, -1.4};
    PointND pt(coords, sizeof(coords) / sizeof(coords[0]));
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}