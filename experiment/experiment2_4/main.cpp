#include <iostream>
#include "myComplex.h"

using namespace std;

int main() {
    myComplex c1;
    myComplex c2;
    myComplex c3,c4,c5;
    cin >> c1;
    c2 = c1;
    c4 = c1;
    c5 = c1;
    cout << "c1的值是： " << c1 << endl;
    cout << "c2的值是： " << c2 << endl;
    c4 *= c1;
    cout << "c4 *= c1的值是:" << c4 << endl;
    c5 /= c1;
    cout << "c5 /= c1的值是:" << c5 << endl;
    c3 = c1 + c2;
    cout << "c1 + c2的结果是：" << c3 << endl;
    c3 = c1 - c2;
    cout << "c1 - c2的结果是：" << c3 << endl;
    c3 = c1 / c2;
    cout << "c1 / c2的结果是：" << c3 << endl;
    c3 = c1 * c2;
    cout << "c1 * c2的结果是：" << c3 << endl;

    return 0;

}