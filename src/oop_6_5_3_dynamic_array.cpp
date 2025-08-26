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
    size_t capacity_{0};
    void resize_vector(size_t new_size);
    void realloc_vector();
public:
    Vector();
    Vector(T* arr, size_t size);
    Vector(const Vector& other) : Vector(other.data, other.length) { }

    void push_back(const T& new_data);
    void push_front(const T& new_data);
    void pop_back();
    void pop_front();

    T& operator[](size_t index);
    Vector operator+(const Vector& right);
    const Vector& operator+=(const Vector& right);
    const Vector& operator= (const Vector& other);
    void remove(size_t index);
    void insert(size_t index, const T& new_data);

    size_t capacity() const { return capacity_; }
    size_t size() const { return length; }
    bool empty() { return length == 0; }
    void clear();
    ~Vector() { delete[] data; }
};

template <typename T>
Vector<T>::Vector() : length(0), capacity_(start_capacity)
{
    data = new T[capacity_];
}

template <typename T>
Vector<T>::Vector(T* arr, size_t size) : length(size), capacity_(start_capacity)
{
    resize_vector(length);

    if (data != nullptr)
        delete[] data;

    data = new T[capacity_];
    std::copy(arr, arr + length, data);
}

template <typename T>
void Vector<T>::resize_vector(size_t new_size)
{
    if (new_size <= capacity_)
        return;

    while (capacity_ < new_size)
        capacity_ *= resize_factor;

    T* temp = new T[capacity_];
    std::copy(data, data + length, temp);
    delete[] data;
    data = temp;
}

template <typename T>
void Vector<T>::realloc_vector()
{
    T* temp = new T[length];
    std::copy(data, data + length, temp);
    delete[] data;
    data = new T[capacity_];
    std::copy(temp, temp + length, data);
    delete[] temp;
}

template <typename T>
void Vector<T>::push_back(const T& new_data)
{
    size_t old_capacity = capacity_;
    resize_vector(length + 1);

    if (old_capacity != capacity_)
        realloc_vector();

    length++;

    data[length - 1] = new_data;
}

template <typename T>
void Vector<T>::push_front(const T& new_data)
{
    size_t old_capacity = capacity_;
    resize_vector(length + 1);

    if (old_capacity != capacity_)
        realloc_vector();

    length++;
    for (size_t i = length - 1; i > 0; i--)
            data[i] = data[i - 1];

    data[0] = new_data;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (length > 0)
        length--;
}

template <typename T>
void Vector<T>::pop_front()
{
    if (length > 0)
    {
        for (size_t i = 0; i < length - 1; i++)
            data[i] = data[i + 1];
        length--;
    }

}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    if (index >= length)
        throw VectorIndexError("Invalid element index.");

    return data[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector& right)
{
    size_t new_length = length + right.length;
    T* new_arr = new T[new_length];
    std::copy(data, data + length, new_arr);
    std::copy(right.data, right.data + right.length, new_arr + length);
    Vector temp(new_arr, new_length);
    delete[] new_arr;

    return temp;
}

template <typename T>
const Vector<T>& Vector<T>::operator+=(const Vector& right)
{
    size_t old_capacity = capacity_;
    size_t old_length = length;

    length += right.length;
    resize_vector(length);

    if (old_capacity != capacity_)
    {
        T* old_data = new T[old_length];
        std::copy(data, data + old_length, old_data);
        realloc_vector();
        std::copy(old_data, old_data + old_length, data);
        delete[] old_data;
    }

    std::copy(right.data, right.data + right.length, data + old_length);

    return *this;
}

template <typename T>
const Vector<T>& Vector<T>::operator= (const Vector& other)
{
    if (this == &other)
        return *this;

    delete[] data;
    length = other.length;
    resize_vector(length);

    data = new T[capacity_];
    std::copy(other.data, other.data + other.length, data);

    return *this;
}

template <typename T>
void Vector<T>::remove(size_t index)
{
    if (index >= length)
        throw VectorIndexError("Invalid element index.");

    for (size_t i = index; i < length - 1; i++)
        data[i] = data[i + 1];

    length--;
}

template <typename T>
void Vector<T>::insert(size_t index, const T& new_data)
{
    if (index > length)
        throw VectorIndexError("Invalid element index.");

    if (index == 0)
    {
        push_front(new_data);
    }
    else if (index == length)
    {
        push_back(new_data);
    }
    else
    {
        size_t old_capacity = capacity_;
        size_t old_length = length;

        length++;
        resize_vector(length);

        if (old_capacity != capacity_)
        {
            T* old_data = new T[old_length];
            std::copy(data, data + old_length, old_data);
            realloc_vector();
            std::copy(old_data, old_data + old_length, data);
            delete[] old_data;
        }

        for (size_t i = length - 1; i > index; i--)
            data[i] = data[i - 1];

        data[index] = new_data;
    }
}

template <typename T>
void Vector<T>::clear()
{
    length = 0;
    capacity_ = start_capacity;
}

int main(void)
{
    Vector<short> ar_d; // создание пустого динамического массива (length = 0, capacity = 8)

    ar_d.push_back(1); // добавление значения в конец
    ar_d.push_back(1);
    ar_d.push_front(2); // добавление значения в начало
    ar_d.push_front(2);
    ar_d.pop_back(); // удаление последнего элемента
    ar_d.pop_front(); // удаление первого элемента

    std::cout << "ar_d list after push-pop:" << std::endl;
    for(size_t i = 0; i < ar_d.size(); ++i)
        std::cout << ar_d[i] << " ";
    std::cout << std::endl;

    ar_d[0] = 5;       // изменение значения первого элемента
    short d = ar_d[1]; // считывание значения второго элемента
    std::cout << "short d = " << d << std::endl;

    std::cout << "ar_d list after index ops:" << std::endl;
    for(size_t i = 0; i < ar_d.size(); ++i)
        std::cout << ar_d[i] << " ";
    std::cout << std::endl;

    int indx = 0;

    ar_d.insert(indx, 70); // вставка элемента по индексу indx со значением 70
    std::cout << "After insert ar_d[0] = " << ar_d[0] << std::endl;
    for(size_t i = 0; i < ar_d.size(); ++i)
        std::cout << ar_d[i] << " ";
    std::cout << std::endl;

    ar_d.remove(indx); // удаление элемента по индексу indx
    std::cout << "ar_d list after remove from [0]:" << std::endl;
    for(size_t i = 0; i < ar_d.size(); ++i)
        std::cout << ar_d[i] << " ";
    std::cout << std::endl;

    size_t cap = ar_d.capacity(); // возвращает поле capacity
    size_t len = ar_d.size(); // возвращает поле length
    std::cout << "ar_d.capacity() = " << cap << ", ar_d.size() = " << len << std::endl;

    Vector<short> ar_d2 = ar_d; // копирование (конструктор копирования)

    std::cout << "ar_d2 list after copy ar_d:" << std::endl;
    for(size_t i = 0; i < ar_d2.size(); ++i)
        std::cout << ar_d2[i] << " ";
    std::cout << std::endl;

    ar_d2 += ar_d; // добавление значений массива ar_d в конец массива ar_d2

    std::cout << "ar_d2 list after += ar_d:" << std::endl;
    for(size_t i = 0; i < ar_d2.size(); ++i)
        std::cout << ar_d2[i] << " ";
    std::cout << std::endl;

    Vector<short> res = ar_d2 + ar_d; // соединение двух массивов (сами массивы ar_d, ar_d2 не меняются)

    std::cout << "res list after ar_d2 + ar_d:" << std::endl;
    for(size_t i = 0; i < ar_d2.size(); ++i)
        std::cout << ar_d2[i] << " ";
    std::cout << std::endl;

    if( !ar_d2.empty() ) // метод empty возвращает true, если массив пуст, и false иначе
    {
        ar_d2.clear(); // удаление всех элементов из массива (параметр length равен 0)
    }
    std::cout << "ar_d2.empty? - " << ar_d2.empty() << std::endl;
    // перебор всех сохраненных значений в динамическом массиве ar_d
    std::cout << "ar_d list after ALL:" << std::endl;
    size_t sz = ar_d.size();
    for(size_t i = 0; i < sz; ++i)
    std::cout << ar_d[i] << " ";

    return EXIT_SUCCESS;
}