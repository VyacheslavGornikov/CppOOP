#include <iostream>

template <typename T>
class Vector
{
    enum {
        resize_factor = 2,
        start_capacity = 8
    };

    T* data{nullptr};
    size_t length{0};
    size_t capacity{0};
    void resize_vector(size_t new_size);
public:
    Vector() : length(0), capacity(start_capacity)
    {
        data = new T[capacity];
    }

    void push_back(const T& data);
    void push_front(const T& data);
    void pop_back();
    void pop_front();

    T& operator[](size_t index);
    void remove(size_t index);
    void insert(size_t index, const T& data);

    size_t capacity() const { return capacity; }
    size_t size() const { return length; }
    bool empty() { return data == nullptr; }
    void clear();
};

template <typename T>
void Vector<T>::resize_vector(size_t new_size)
{
    if (new_size <= capacity)
        return;

    while (capacity < new_size)
        capacity *= resize_factor;

    T* temp = new T[capacity];
    std::copy(data, data + length, temp);
    delete[] data;
    data = temp;
}

template <typename T>
void Vector<T>::clear()
{
    for (size_t i = 0; i < length; i++)
    {
        delete data[i];
        data[i] = nullptr;
    }
    length = 0;
}