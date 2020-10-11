//
// Created by yang zhengtao on 2020/10/10.
//
#include "iostream"
using namespace std;

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i){}
    Complex operator+ (const Complex &c) const;
    Complex operator- (const Complex &c) const;
    void display() const;

private:
    double real;
    double imag;
};

Complex Complex::operator+(const Complex &c) const {
    return Complex(real + c.real, imag+c.imag);
}

Complex Complex::operator-(const Complex &c) const {
    return Complex(real - c.real, imag - c.imag);
}

void Complex::display() const {
    cout<<"("<<real<<", "<<imag<<"i)"<<endl;
}

int main(){
    Complex c1(10, 200), c2(0, 19), c3;
    cout<<"c1 = ";
    c1.display();
    cout<<"c2 = ";
    c2.display();

    cout<<"c1 + c2 = ";
    c3 = c1 + c2;
    c3.display();

    return 0;
}
