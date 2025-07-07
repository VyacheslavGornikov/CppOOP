#include <iostream>

class ColorRGB {
    unsigned char r{0}, g{0}, b{0};
public:
    ColorRGB() = default;
    ColorRGB(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b)
    { 
        if (r > 255) this->r = 255; 
        if (g > 255) this->g = 255;
        if (b > 255) this->b = 255;
    }
    unsigned get_color() { return r + g*256 + b*65536; }
    friend ColorRGB operator + (const ColorRGB& left, const ColorRGB& right);
    void print_rgb() { std::cout << (int)r << " " << (int)g << " " << (int)b << std::endl; }
};

ColorRGB operator + (const ColorRGB& left, const ColorRGB& right)
{
    ColorRGB temp;
    temp.r = left.r + right.r > 255 ? 255 : left.r + right.r;
    temp.g = left.g + right.g > 255 ? 255 : left.g + right.g;
    temp.b = left.b + right.b > 255 ? 255 : left.b + right.b;
    return temp;
}

int main(void)
{
    ColorRGB r1(255, 102, 0);
    ColorRGB r2(100, 100, 100);
    ColorRGB res = r1 + r2;

    res.print_rgb();
}