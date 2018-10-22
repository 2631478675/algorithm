#include "MatrixUDG.h"

#define MAX    100
#define INF    (~(0x1<<31))        // 无穷大(即0X7FFFFFFF)
int main() {
    int prev[MAX] = {0};
    int dist[MAX] = {0};
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int matrix[][9] = {
            /*A*//*B*//*C*//*D*//*E*//*F*//*G*/
            /*A*/ {0,   12,  INF, INF, INF, 16, 14},
            /*B*/
                  {12,  0,   10,  INF, INF, 7, INF},
            /*C*/
                  {INF, 10,  0, 3,     5,   6, INF},
            /*D*/
                  {INF, INF, 3, 0,     4, INF, INF},
            /*E*/
                  {INF, INF, 5, 4,     0,   2,  8},
            /*F*/
                  {16,  7,   6,   INF, 2,   0,  9},
            /*G*/
                  {14,  INF, INF, INF, 8,   9,  0}};
    int vlen = sizeof(vexs) / sizeof(vexs[0]);
    MatrixUDG *pG;

    pG = new MatrixUDG(vexs, vlen, matrix);

    pG->print();   // 打印图

    // dijkstra算法获取"第4个顶点"到其它各个顶点的最短距离
    pG->dijkstra(3, prev, dist);

    return 0;
}