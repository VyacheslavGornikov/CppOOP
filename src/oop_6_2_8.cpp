#include <iostream>
//#include <cmath>

// здесь объявляйте функцию
template <typename T>
void ar_sort (T* arr, size_t size, bool (*compare) (T a, T b));

int main()
{
    // здесь продолжайте функцию main
    //int data[] = {5, -3, 10, 0, 33, 7, -12};
    int data[] = {0.1, -0.3, 2.3, -3.0, 2.0, -1.2};
    ar_sort<int> (data, sizeof(data) / sizeof(*data),
                  [] (int a, int b) { return std::abs(a) < std::abs(b); });
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}

template <typename T>
void ar_sort (T* arr, size_t size, bool (*compare) (T a, T b))
{
    for (size_t i = 1; i < size; i++)
    {
        T key = arr[i];
        long j = static_cast<long>(i) - 1;
        while (j >= 0 && compare(key, arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

