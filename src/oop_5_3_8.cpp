#include <iostream>

// здесь объявляйте класс
class Vector3D
{
    enum {min_coord = -100, max_coord = 100};
    int x{0}, y{0}, z{0}; // координаты в трехмерном пространстве
    bool is_valid_coords(int x, int y, int z)
    {
        if (x < min_coord || x > max_coord || y < min_coord || y > max_coord ||
            z < min_coord || z > max_coord)
            return false;
        return true;
    }
public:
    Vector3D(int x = 0, int y = 0, int z = 0)
    {
        if (!is_valid_coords(x, y, z))
            throw -2;
        this->x = x; this->y = y; this->z = z;
    }
    void get_coords(int& x, int& y, int& z) const
    { x = this->x; y = this->y; z = this->z; } // возвращает значения координат
    void set_coords(int x, int y, int z)
    {
        if (!is_valid_coords(x, y, z))
            throw -1;
        this->x = x; this->y = y; this->z = z;
    } // задает значения координат
    int& operator[] (int index)
    {
        if(index == 0) return x;
        else if (index == 1) return y;
        else if (index == 2) return z;
        else throw "Incorrect index.";
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    try
    {
        Vector3D v3(10, 1000, -500);
    }
    catch (int ex)
    {
        std::cout << ex;
    }
    catch (const char* ex)
    {
        std::cout << ex;
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}