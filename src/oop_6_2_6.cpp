#include <iostream>

// здесь объявляйте классы и функцию
class ValueError : public std::exception
{
    std::string msg;
public:
    ValueError(const std::string& message) noexcept : msg(message) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class Window
{
    int width {0}, height {0};
public:
    Window(int width, int height) : width(width), height(height)
    {
        if (width < 0 || height < 0)
            throw ValueError("The value must be positive");
        this->width = width;
        this->height = height;
    }
    void get_data(int& width, int& height) const
    {
        width = this->width; height = this->height;
    }
};

class Rect
{
    double width {0}, height {0};
public:
    Rect(double width, double height) : width(width), height(height)
    {
        if (width < 0 || height < 0)
            throw ValueError("The value must be positive");
        this->width = width;
        this->height = height;
    }
    void get_data(double& width, double& height) const
    {
        width = this->width; height = this->height;
    }
};

template <typename T, typename Dims_type = int>
Dims_type get_square(const T& obj)
{
    Dims_type w, h;
    obj.get_data(w, h);
    return w * h;
}

int main()
{
    // здесь продолжайте функцию main
    try
    {
        Window wnd(100, -5);
        int res_sq = get_square(wnd);
        std::cout << res_sq;
    }
    catch(const ValueError& e)
    {
        std::cout << e.what();
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}