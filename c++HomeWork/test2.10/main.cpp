#include <iostream>

using namespace std;
int main() {
   int a = 2,b =4;
//   cout << (a = b = a) <<" " << a << " " << b << endl;  2 2 2
//    cout << (b -= a ++) <<" " << a << " " << b << endl; 2 3 2
//    cout << (a -= b *= b /=2) << a << " " << b << endl; -2-2 4
//   cout << (b >=a) << " "; 1 2 4
//    cout << (a && a > 0) << a << " " << b << endl; 1 2 4
//    cout << (a = b /10 ? 1 : 0) << " " << a << " " << b << endl; 0 0 4
//    cout << ( b = a/b ,a*b) << " " << a << " " << b << endl; 0 2 0
    return 0;
}