#include <iostream>

template <typename T = int>
class Array {
    T* data {nullptr};
    size_t size {0};
public:
    Array() = default;
    Array(T* d, size_t size) : size(size)
    {
        // создание массива data и копирование в него значений из массива d
        data = new T[size];
        this->size = size;
        for (size_t i = 0; i < size; i++)
            data[i] = d[i];
    }
    Array(const Array& other)
    {
    	// конструктор копирования
        delete[] data;
        data = new T[other.size];
        this->size = other.size;
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~Array() { delete[] data; }

    Array operator+(const Array& right)
    {
        // здесь реализация операции объединения массивов data и сохранение результата в объекте array_obj
        // сначала должны идти значения массива this->data, а затем, массива right.data
        T* temp = new T[size + right.size];
        std::copy(data, data + size, temp);
        std::copy(right.data, right.data + right.size, temp + size);
        Array array_obj(temp, size + right.size);
        delete[] temp;
        return array_obj;
    }
    const Array& operator=(const Array& right)
    {
        // здесь реализация операции присваивания и сохранение результата в текущем объекте this
        if (this == &right)
            return right;
        delete[] data;
        data = new T[right.size];
        this->size = right.size;
        for (size_t i = 0; i < size; i++)
            data[i] = right.data[i];
        return *this;
    }

    const T* get_data() const { return data; }
    size_t get_length() const { return size; }
};

int main()
{
    return 0;
}