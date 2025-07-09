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
    ~PointND() { delete[] coords; }

    size_t get_dims() const { return dims; }

    short& operator[] (size_t index)
    {
        static short dummy = 0;
        if (index < 0 || index > dims - 1) return dummy;
        return coords[index];
    }

    const PointND& operator= (const PointND& other)
    {
        if (this == &other) return other;
        delete[] coords;
        dims = other.dims;
        coords = new short[dims];
        std::copy(other.coords, other.coords + dims, coords);
        return *this;
    }

    void operator++ ()
    {
        for (size_t i = 0; i < dims; i++)
            coords[i]++;
    }

    void operator-- ()
    {
        for (size_t i = 0; i < dims; i++)
            coords[i]--;
    }

    void operator++ (int)
    {
        for (size_t i = 0; i < dims; i++)
            coords[i]++;
    }

    void operator-- (int)
    {
        for (size_t i = 0; i < dims; i++)
            coords[i]--;
    }

    const PointND& operator+= (const PointND& right)
    {
        if (dims != right.dims) return *this;
        for (size_t i = 0; i < dims; i++)
            coords[i] += right.coords[i];
        return *this;
    }

    const PointND& operator-= (const PointND& right)
    {
        if (dims != right.dims) return *this;
        for (size_t i = 0; i < dims; i++)
            coords[i] -= right.coords[i];
        return *this;
    }
};

int main(void)
{
    short coords[] = {1, 2, 3, 4, 5};
    PointND pt(coords, sizeof(coords) / sizeof(coords[0]));
    int indx = 0;
    int val = pt[indx]; // получение значения координаты по индексу (от 0 до dims-1); если указывается не верный индекс, то возвращается 0
    pt[indx + 1] = val; // присвоение координате с индексом indx значения val; если указывается не верный индекс, то ничего не присваивается
    std::cout << val << " " << pt[indx + 1] << std::endl;
    for (size_t i = 0; i < pt.get_dims(); i++)
    {
        std::cout << pt[i] << " ";
    }
    std::cout << std::endl;
    printf("pt2\n");
    PointND pt2;
    pt2 = pt; // в объекте pt2 создается свой массив coords с поэлементным копированием данных из объекта pt1 (поле dims также копируется)
    for (size_t i = 0; i < pt2.get_dims(); i++)
    {
        std::cout << pt2[i] << " ";
    }
    std::cout << std::endl;
    pt2++; // увеличение каждой координаты на 1
    for (size_t i = 0; i < pt2.get_dims(); i++)
    {
        std::cout << pt2[i] << " ";
    }
    std::cout << std::endl;
    ++pt2; // увеличение каждой координаты на 1
    for (size_t i = 0; i < pt2.get_dims(); i++)
    {
        std::cout << pt2[i] << " ";
    }
    std::cout << std::endl;
    printf("pt\n");
    pt--; // уменьшение каждой координаты на 1
    for (size_t i = 0; i < pt.get_dims(); i++)
    {
        std::cout << pt[i] << " ";
    }
    std::cout << std::endl;
    --pt; // уменьшение каждой координаты на 1
    for (size_t i = 0; i < pt.get_dims(); i++)
    {
        std::cout << pt[i] << " ";
    }
    std::cout << std::endl;
    pt += pt2; // к координатам coords объекта pt прибавляются соответствующие координаты объекта pt2
    for (size_t i = 0; i < pt.get_dims(); i++)
    {
        std::cout << pt[i] << " ";
    }
    std::cout << std::endl;
    pt -= pt2; // из координат coords объекта pt вычитаются соответствующие координаты объекта pt2
    for (size_t i = 0; i < pt.get_dims(); i++)
    {
        std::cout << pt[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}