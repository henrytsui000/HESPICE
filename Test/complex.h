#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double real, double imag);
    void set_value(double real, double imag);
    Complex get_value(void);
    Complex operator+(Complex other);
    Complex operator*(Complex other);
    Complex operator/(Complex other);
};

#endif // COMPLEX_H
