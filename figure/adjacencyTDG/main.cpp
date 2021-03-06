#include <iostream>
#include "TableDirectedGraph.h"

int main() {
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
            {'A', 'B'},
            {'B', 'C'},
            {'B', 'E'},
            {'B', 'F'},
            {'C', 'E'},
            {'D', 'C'},
            {'E', 'B'},
            {'E', 'D'},
            {'F', 'G'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    TableDirectedGraph * pG;
    TableDirectedGraph * pGByAutomatic;

    // 采用已有的"图"
    pGByAutomatic = new TableDirectedGraph(vexs, vlen, edges, elen);
    pGByAutomatic->print();

    // 自定义"图"(输入矩阵队列)
    pG = new TableDirectedGraph();
    pG->print();   // 打印图

    return 0;
}