#include <iostream>
#include <string>

// здесь объявляйте класс
class ArrayInt
{
    int* data {nullptr}; // массив целых чисел
    size_t size {0}; // длина массива (число элементов)
    void check_index(size_t index)
    {
        if (index < 0 || index > size - 1)
            throw "Incorrect index.";
    }
public:
    ArrayInt() = default;
    ArrayInt(int* arr, size_t arr_size)
    {
        set_data(arr, arr_size);
    }
    ~ArrayInt() { delete[] data; }
    void set_data(int* d, size_t length)
    {
        if (d != nullptr && length > 0)
        {
            size = length;
            delete[] data;
            data = new int[size];
            for (size_t i = 0; i < size; i++)
                data[i] = d[i];
        }
    } // создает новый массив data с переданными значениями d в количестве length
    int* get_data() const { return data; } // возвращает массив data
    size_t get_size() const { return size; } // возвращает значение поля size

    int& operator[] (size_t index)
    {
        check_index(index);
        return data[index];
    }
};



