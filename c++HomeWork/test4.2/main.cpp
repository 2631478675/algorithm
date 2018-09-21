#include <iostream>
using namespace std;
int f(int n){
    return ++n;
}
int& g(int& n){
    return  ++n;
}
int h(char n){
    return ++n;
}
int main() {
    int a =1,b= 2,c=3;
//    cout << g(a) << " ";
    cout << f(g(a)) << " ";
    cout << g(g(b)) << " ";
    cout << h(g(c)) << endl;
    cout << a << " " << b << " " << c << endl;

    return 0;
}