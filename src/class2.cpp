#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Point2D
{
private:
    const unsigned maxCoord {100};
    int x,y; // или int x{0},y{0}
public:
    /* Конструктор по умолчанию с списком инициализации
       x(0), y(0) порядок важен (int x,y;)! */
    // Point2D () : x(0), y(0){}

    /* Конструктор по умолчанию с списком инициализации
       x(a), y(b) порядок важен (int x,y;), можно инициализировать объект
       при создании */
    // Point2D () : x(0), y(0){}
    Point2D (int a = 0, int b = 0) : x(a), y(b)
    { std :: cout << "Constructor called" << endl; }

    void SetCoords (int a, int b)
    {
        x = a;
        y = b;
    }
    void GetCoords (int& a, int& b)
    {
        a = x;
        b = y;
    }

    bool SetCoordsRange (int a, int b, int minCoord = 0, int maxCoord = 100)
    {
        if (a < minCoord || a > maxCoord || b < minCoord || b > maxCoord)
            return false;

        SetCoords (a, b);
        return true;
    }

    double LengthTo (Point2D& pt)
    {
        return sqrt ((x - pt.x) * (x - pt.x) + (y - pt.y) * (y - pt.y));
    }
};


int main (void)
{
    // Point2D pt (1, 2);
    // Point2D* ptrPt = new Point2D (10,20);
    //Point2D arrPt[5];
    int x, y;
    // pt.GetCoords (x, y);
    // for (int i = 0; i < 5; i++)
    // {
    //     arrPt[i].GetCoords (x, y);
    //     std :: cout << x << " " << y << std :: endl;
    //     std :: cout << endl;
    // }

    //std :: cout << x << " " << y << std :: endl;
    // delete ptrPt;
    return EXIT_SUCCESS;
}
