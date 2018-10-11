#include <iostream>
#include "MatrixUDG.h"


using namespace std;


int main() {
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
            {'A', 'C'},
            {'A', 'D'},
            {'A', 'F'},
            {'B', 'C'},
            {'C', 'D'},
            {'E', 'G'},
            {'F', 'G'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    MatrixUDG* pG;

    // 自定义"图"(输入矩阵队列)
    pG = new MatrixUDG();

    // 采用已有的"图"
//    pG = new MatrixUDG(vexs, vlen, edges, elen);

    pG->print();   // 打印图

    return 0;
}