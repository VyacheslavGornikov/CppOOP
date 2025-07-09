#include <iostream>

class LimitLength
{
    enum {min_length = -10, max_length = 10}; // границы допустимых значений
    int length {0}; // текущее значение
public:
    LimitLength(int len = 0) : length(len)
    {
        if (length < min_length) length = min_length;
        else if (length > max_length) length = max_length;
    }

    int get_length() const { return length; }

    int operator++ ()
    {
        length + 1 > max_length ? length = max_length : ++length;
        return length;
    }
    int operator-- ()
    {
        length - 1 < min_length ? length = min_length : --length;
        return length;
    }
    int operator++ (int)
    {
        int val = length;
        length + 1 > max_length ? length = max_length : ++length;
        return val;
    }
    int operator-- (int)
    {
        int val = length;
        length - 1 < min_length ? length = min_length : --length;
        return val;
    }

    int operator+= (int len)
    {
        length + len > max_length ? length = max_length : length += len;
        return length;
    }
    int operator-= (int len)
    {
        length - len < min_length ? length = min_length : length -= len;
        return length;
    }
    int operator*= (int len)
    {
        if (length * len > max_length) length = max_length;
        else if (length * len < min_length) length = min_length;
        else length *= len;
        return length;
    }
    int operator/= (int len)
    {
        if (length / len > max_length) length = max_length;
        else if (length / len < min_length) length = min_length;
        else length /= len;
        return length;
    }

    operator int() const { return length; }
};

int main(void)
{
    LimitLength lm1 = -5;
    int a = lm1++;
    int b = ++lm1;
    int c = lm1--;
    int d = --lm1;
    std::cout << a << " " << b << " " << c << " " << d << std::endl;
    int res_1 = lm1 += 5;
    int res_2 = lm1 -= 15;
    int res_3 = lm1 *= 2;
    int res_4 = lm1 /= 3;
    std::cout << res_1 << " " << res_2 << " " << res_3 << " " << res_4 <<
    std::endl;
    return 0;
}