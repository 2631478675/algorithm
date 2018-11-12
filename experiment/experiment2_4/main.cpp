#include <iostream>
#include "myComplex.h"

using namespace std;

int main() {
    myComplex c1;
    myComplex c2;
    myComplex c3;
    cin >> c1;
    c2 = c1;
    cout << "c1的值是： " << c1 << endl;
    cout << "c2的值是： " << c2 << endl;4
    c3 = c1 / c2;
    cout << "c1 / c2的结果是：" << c3 << endl;
    c3 = c1 * c2;
    cout << "c1 * c2的结果是：" << c3 << endl;

    return 0;

}