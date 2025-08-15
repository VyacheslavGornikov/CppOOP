#include <iostream>

// здесь объявляйте классы
class ColorRGBError : public std::exception
{
    std::string msg;
public:
    ColorRGBError(const std::string& msg) noexcept : msg(msg) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class ColorRGBValueError : public ColorRGBError
{
public:
    ColorRGBValueError(const std::string& msg) noexcept : ColorRGBError(msg) {}
};

class ColorRGBIndexError : public ColorRGBError
{
public:
    ColorRGBIndexError(const std::string& msg) noexcept : ColorRGBError(msg) {}
};

class ColorRGB
{
    short r{0}, g{0}, b{0};

    class Proxy
    {
        ColorRGB& color;
        int index = -1;
    public:
        Proxy(ColorRGB& obj, int index) : color(obj), index(index) {}
        operator short() const
        {
            if (index == 0) return color.r;
            else if (index == 1) return color.g;
            else if (index == 2) return color.b;
            else throw ColorRGBIndexError("Index must be in range [0; 2]");
        }

        Proxy& operator= (short value)
        {
            color.validate(value);
            if (index == 0) color.r = value;
            else if (index == 1) color.g = value;
            else if (index == 2) color.b = value;
            else throw ColorRGBIndexError("Index must be in range [0; 2]");
            return *this;
        }
    };
public:
    ColorRGB(short red = 0, short green = 0, short blue = 0)
    {
        set_rgb(red, green, blue);
    }
    void validate(short value) const
    {
        if (value < 0 || value > 255)
            throw ColorRGBValueError("Valid values must be in the range [0; 255]");
    }
    void set_rgb(short r, short g, short b)
    {
        validate(r);
        validate(g);
        validate(b);
        this->r = r;
        this->g = g;
        this->b = b;
    }// в соответствующие поля заносятся переданные значения

    short get_r() const { return r; }
    short get_g() const { return g; }
    short get_b() const { return b; }

    Proxy operator[] (int index)
    {
        return Proxy(*this, index);
    }
};

int main()
{
    // здесь продолжайте функцию main
    try
    {
        ColorRGB yellow (255, 201, -14);
    }
    catch (const ColorRGBIndexError& idx_err)
    {
        std::cout << idx_err.what();
    }
    catch (const ColorRGBValueError& val_err)
    {
        std::cout << val_err.what();
    }
    catch (const ColorRGBError& com_err)
    {
        std::cout << com_err.what();
    }
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}