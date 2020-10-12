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
    friend ostream &operator << (ostream &out, const Complex &c); // 运算符 << reload with friend function
//    void display() const;

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

//void Complex::display() const {
//    cout<<"("<<real<<", "<<imag<<"i)"<<endl;
//}

// 运算符 << reload
ostream &operator << (ostream &out, const Complex &c){
    out<<"("<<c.real<<", "<<c.imag<<")"<<endl;
}

int main(){
    Complex c1(10, 200), c2(0, 19), c3;
    cout<<"c1 = "<<c1;
    cout<<"c2 = "<<c2;

    c3 = c1 + c2;
    cout<<"c1 + c2 = "<<c3;
    return 0;
}
