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
    MatrixUDG* pGByAutomatic;

    // 采用已有的"图"
    pGByAutomatic = new MatrixUDG(vexs, vlen, edges, elen);
    pGByAutomatic->print();


    // 自定义"图"(输入矩阵队列)
    pG = new MatrixUDG();
    pG->print();

    return 0;
}