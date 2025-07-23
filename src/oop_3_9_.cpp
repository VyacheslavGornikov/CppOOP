#include <iostream>

// здесь объявляйте класс
#include <iostream>

class CoordsND {
    enum {max_coords = 10};
    int *coords {nullptr}; // массив значений координат
    int size {0}; // количество координат (не более max_coords)
public:
    CoordsND() = default;
    CoordsND(int* lst, int sz)
    {
        size = (sz > max_coords) ? max_coords : sz;

        coords = new int[size];
        for(int i = 0;i < size; ++i)
            coords[i] = lst[i];
    }
    CoordsND (const CoordsND& other) : CoordsND(other.coords, other.size)
    {}
    CoordsND (CoordsND&& move) noexcept
    {
        size = (move.size > max_coords) ? max_coords : move.size;
        coords = move.coords;
        move.coords = nullptr;
    }
    const CoordsND& operator= (const CoordsND& other)
    {
        if (this == &other) return *this;
        delete[] coords;
        size = other.size;
        coords = new int[size];
        for (int i = 0; i < size; i++)
            coords[i] = other.coords[i];
        return *this;
    }
    CoordsND& operator= (CoordsND&& other) noexcept
    {
        if (this == &other) return *this;
        size = other.size;
        coords = other.coords;
        other.coords = nullptr;
        return *this;
    }
    ~CoordsND() { delete[] coords; }

    int* get_coords() { return coords; }
    int get_size() const { return size; }
};

int main()
{
    // здесь продолжайте функцию main
    int lst[] = {-4, 10, 0, 77, 14};
    CoordsND coords (lst, sizeof(lst) / sizeof(lst[0]));
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}