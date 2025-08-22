#include <iostream>

class VectorIndexError : public std::exception
{
    std::string msg;
public:
    VectorIndexError(const std::string& message) : msg(message) { }
    const char* what() const noexcept override { return msg.c_str(); }
};

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
    Vector() : length(0), capacity(start_capacity);
    Vector(T* arr, size_t size);
    Vector(const Vector& other) : Vector(other.data, other.length) { }

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
Vector<T>::Vector() : length(0), capacity(start_capacity)
{
    data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(T* arr, size_t size)
{
    length = size;
    resize_vector(length);

    data = new T[capacity];

    std::copy(arr, arr + length, data);
}

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
void Vector<T>::push_back(const T& data)
{
    T* temp = new T[length];

    length++;
    resize_factor(length);

    delete[] data;
    data = new T[capacity];
    std::copy(temp, temp + length - 1, data);

    data[length - 1] = data;
}

template <typename T>
void Vector<T>::push_front(const T& data)
{

}

template <typename T>
void Vector<T>::pop_back()
{

}

template <typename T>
void Vector<T>::pop_front()
{

}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    if (index > length)
        throw VectorIndexError("Invalid element index.");

    return data[index];
}

template <typename T>
void Vector<T>::remove(size_t index)
{
    if (index > length)
        throw VectorIndexError("Invalid element index.");

    for (size_t i = index; i < length - 1; i++)
        data[i] = data[i + 1];

    length--;
}

template <typename T>
void Vector<T>::insert(size_t index, const T& data)
{

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