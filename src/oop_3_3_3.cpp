#include <iostream>

class Array {
    int* data {nullptr};
    size_t size {0};
public:
    Array() = default;
    Array(int *dt, size_t sz) : size(sz)
    {
        if (size > 0)
        {
            data = new int[size]{0};
            for (size_t i = 0; i < size; i++)
                data[i] = dt[i];
        }
    }
    void set_data(int* d, size_t length)
    {
        delete[] data;
        size = length;
        data = new int[size];

        for(size_t i = 0; i < size; ++i)
            data[i] = d[i];
    }

    int* get_data() { return data; }
    size_t get_size() const { return size; }
    Array operator + (const Array& other)
    {
        Array result;
        result.size = this->size + other.size;
        result.data = new int[result.size];
        std::copy(data, data + size, result.data);
        std::copy(other.data, other.data + other.size, result.data + size);

        return result;
    }

    const Array& operator = (const Array& other)
    {
        if (this == &other) return other;

        delete[] data;
        size = other.size;
        if (size > 0)
        {
            data = new int[size];
            if (data == NULL) exit(EXIT_FAILURE);

            for (size_t i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
        {
            data = nullptr;
        }

        return *this;
    }

    ~Array() { delete[] data; }
};

int main(void)
{
    int arr1[2] = {1, 2};
    int arr2[3] = {3, 4, 5};
    int arr3[2] = {6, 7};
    Array ar1(arr1, sizeof(arr1)/sizeof(arr1[0]));
    Array ar2(arr2, sizeof(arr2)/sizeof(arr2[0]));
    Array ar3(arr3, sizeof(arr3)/sizeof(arr3[0]));
    Array res_1;
    res_1 = ar1 + ar2;
    int* arr_ptr = res_1.get_data();
    for (size_t i = 0; i < res_1.get_size(); i++)
    {
        std::cout << arr_ptr[i] << " ";
    }
    std::cout << std::endl;
    Array res_2 = ar1 + ar2 + ar3;

    arr_ptr = res_2.get_data();

    for (size_t i = 0; i < res_2.get_size(); i++)
    {
        std::cout << arr_ptr[i] << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}