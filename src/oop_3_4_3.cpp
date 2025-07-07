#include <iostream>

class PointND {
    short* coords {nullptr}; // координаты точки
    size_t dims {0}; // число координат
public:
	PointND() = default;
    PointND(short* cds, size_t len) : dims(len)
    {
        coords = new short[dims];
        for(size_t i = 0;i < dims; ++i)
            coords[i] = cds[i];
    }
    PointND (const PointND& other) : PointND(other.coords, other.dims)
    {}
    ~PointND() { delete[] coords; }

    short operator [] (size_t index) const
    {
        if (index >= 0 && index < dims) return coords[index];
        return 0;
    }

    short& operator [] (size_t index)
    {
        static short dummy;
        if (index >= 0 && index < dims) return coords[index];
        return dummy;
    }

    const PointND& operator = (const PointND& other)
    {
        if (this == &other) return other;

        delete[] coords;
        dims = other.dims;
        coords = new short[dims];
        for (size_t i = 0; i < dims; i++)
        {
            coords[i] = other.coords[i];
        }
        return *this;
    }

};

int main(void)
{
short coords[] = {1, 2, 3, 4, 5};
PointND pt(coords, sizeof(coords) / sizeof(coords[0]));
int indx = 1;
int val = pt[indx]; // получение значения координаты по индексу (от 0 до dims-1); если указывается не верный индекс, то возвращается 0
pt[indx] = val; // присвоение координате с индексом indx значения val; если указывается не верный индекс, то ничего не присваивается
PointND pt2, pt1;
pt2 = pt1; // в объекте pt2 создается свой массив coords с поэлементным копированием данных из объекта pt1 (поле dims также копируется)
    return 0;
}