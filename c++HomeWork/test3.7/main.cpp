#include <iostream>

using namespace std;

int division(int a, int b)
{
    if( b == 0 )
    {
        throw "Division by zero condition!";
    }
    return (a/b);
}
int main() {
    int a, b;
    char c;
    cout << "请输入";
    cin >> a >> c >> b;
    try {
        switch (c) {
            case '*':
                cout << a * b << endl;
                break;
            case '+':
                cout << a + b << endl;
                break;
            case '-':
                cout << a - b << endl;
                break;
            case '%':
                cout << a % b << endl;
                break;
            case '/':
                int z= division(a,b);
                cout << z << endl;
                break;
        }
    }catch (const char* msg) {
        cerr << msg << endl;
    }


    return 0;
}