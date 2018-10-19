//
// Created by I500042 on 10/5/2018.
//

#ifndef EXPERIMENT2_4_MYCOMPLEX_H
#define EXPERIMENT2_4_MYCOMPLEX_H

#include <iostream>

#include <cmath>
#include <string.h>

using namespace std;


/**
 * 复数z=a+bi
 * 实部：a
 * 虚部：b
 * 模： |z|=√(a²+b²)
 */
class myComplex {
private:
    double real;
    double imag;
public:
    /**
     * constructor
     */
    myComplex();

    myComplex(double a);

    myComplex(double a, double b);

    myComplex(myComplex &v);


    double getReal();  //返回复数的实部
    double getImaginary();  //返回复数的虚部
    double getModulus(); //返回复数的模

    void setReal(double r);  //设置复数的实部
    void setImaginary(double i);  //设置复数的虚部

    myComplex &operator=(const myComplex &rhs);  //类对象的赋值

    myComplex &operator+=(myComplex &rhs);

    myComplex &operator-=(myComplex &rhs);

    myComplex &operator*=(myComplex &rhs);

    myComplex &operator/=(myComplex &rhs);

    friend myComplex operator+(myComplex m, myComplex n);

    friend myComplex operator-(myComplex m, myComplex n);

    friend myComplex operator*(myComplex m, myComplex n);

    friend myComplex operator/(myComplex m, myComplex n);


    friend ostream &operator<<(ostream &os, myComplex &c);

    friend istream &operator>>(istream &is, myComplex &c);
};

myComplex::myComplex() {}

myComplex::myComplex(double a) : real(a) {}

myComplex::myComplex(double a, double b) : real(a), imag(b) {}

myComplex::myComplex(myComplex &v) : real(v.real), imag(v.imag) {}

double myComplex::getImaginary() {
    return this->imag;
}

double myComplex::getReal() {
    return this->real;
}

double myComplex::getModulus() {
    return sqrt(this->imag * this->imag + this->real * this->real);
}

void myComplex::setReal(double r) {
    this->real = r;
}

void myComplex::setImaginary(double i) {
    this->imag = i;
}

myComplex &myComplex::operator=(const myComplex &rhs) {
    this->real = rhs.real;
    this->imag = rhs.imag;
    return *this;
}

myComplex &myComplex::operator+=(myComplex &rhs) {
    this->real += rhs.real;
    this->imag += rhs.imag;
    return *this;
}

myComplex &myComplex::operator-=(myComplex &rhs) {
    this->real -= rhs.real;
    this->imag -= rhs.imag;
    return *this;
}

myComplex &myComplex::operator*=(myComplex &rhs) {
    return *this = *this * rhs;
}

myComplex &myComplex::operator/=(myComplex &rhs) {
    *this = *this / rhs;
    return *this ;
}

myComplex* operator+(myComplex m, myComplex n) {
    myComplex complex;
    complex.real = m.real + n.real;
    complex.imag = m.imag + n.imag;
    return complex;
}

myComplex operator-(myComplex m, myComplex n) {
    myComplex complex;
    complex.real = m.real - n.real;
    complex.imag = m.imag - n.imag;

    return complex;
}

myComplex operator*(myComplex m, myComplex n) {
    myComplex complex;
    complex.real = m.real * n.real - m.imag * n.imag;
    complex.imag = m.imag * n.real + m.real * n.imag;

    return complex;
}

myComplex operator/(myComplex m, myComplex n) {
    myComplex complex;
    double denominator = n.real * n.real + n.imag * n.imag;
    complex.real = (m.real * n.real + m.imag * n.imag) / denominator;
    complex.imag = (m.real * n.imag - m.imag * n.real) / denominator;

    return complex;
}

ostream &operator<<(ostream &os, myComplex &c) {
    if (c.imag < 0.0) {
        os << c.real << " - " << -(c.imag) << "i";
    } else {
        os << c.real << " + " << c.imag << "i";
    }
    return os;
}

istream &operator>>(istream &is, myComplex &c) {
    is >> c.real;
    is >> c.imag;
    return is;
}

#endif //EXPERIMENT2_4_MYCOMPLEX_H
