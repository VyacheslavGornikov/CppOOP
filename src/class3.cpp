#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Complex {
	double re;
	double im;

	public:
	Complex() : re(0.0), im(0.0)
		{ }
        /* Конструктор преобразования, explicit запрещает неявное преобразоание
           как в случае с  c2.add (4.3); */
	explicit Complex(double real) : re(real), im(0.0)
		{ }
		Complex(double real, double imag) : re(real), im(imag)
		{ }
		void get_data(double& re, double& im)
		{
			re = this->re;
			im = this->im;
		}

        const Complex& add (const Complex& other)
        {
            this->re += other.re;
            this->im += other.im;
            return *this;
        }
};


int main (void)
{
    Complex c1;
    Complex c2 (0.5); // or Complex c2 = 0.5
    Complex c3 (-5.4, 7.8); // or Complex c3 = {-5.4, 7.8}

    /* c2.add (4.3); работает конструктор с 1 параметром, создается временный
       объект */
    // c2.add (4.3);

    double re, im;

    c2.get_data (re, im);

    cout << re << " " << im << endl;

    return EXIT_SUCCESS;
}
