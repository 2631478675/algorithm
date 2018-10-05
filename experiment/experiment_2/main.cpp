#include <iostream>
#include "cube.h"
using namespace std;
int main() {
    Box *box = new Box(10,10,10);
    int vo = box ->volume(box);
    int sa = box->SurfaceArea(box);
    cout << "此个Box的体积是：" << vo << endl;
    cout << "此个Box的表面积是：" << sa <<endl;
    int high = 1,width = 3,length = 5;
    box ->change(length,width,high);
    int vo1 = box ->volume(box);
    int sa2 = box->SurfaceArea(box);
    cout << "此个Box的体积是：" << vo1 << endl;
    cout << "此个Box的表面积是：" << sa2 <<endl;
    int high2 = 10,width2 = 30,length2 = 5;
    box ->change(&length2,&width2,&high2);
    int vo2 = box ->volume(box);
    int sa3 = box->SurfaceArea(box);
    cout << "此个Box的体积是：" << vo2 << endl;
    cout << "此个Box的表面积是：" << sa3 <<endl;
    return 0;
}