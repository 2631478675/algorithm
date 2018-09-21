#include <iostream>
using namespace std;
int main() {
    int a= 1;
    int *p = &a;
//    cout << *p << " " << * &a << " " << & * p << " " << ++ *p << endl; 2 2 010FFE24 2
    //cout << *p -- << endl; 1
    int b = (*p) --;
    cout << b << endl;  1
    return 0;
}