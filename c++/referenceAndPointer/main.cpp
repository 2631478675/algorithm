#include <iostream>

using namespace std;
void ReferencePointer()
{
    int i =5;
    int* p = &i;
    int*& pr = p;  //指针的引用，与p指向同一变量i
}
int main() {
    ReferencePointer();
    return 0;
}