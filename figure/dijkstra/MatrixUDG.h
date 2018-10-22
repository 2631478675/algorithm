//
// Created by 刘元林 on 2018/10/15.
//

#ifndef DIJKSTRA_MATRIXUDG_H
#define DIJKSTRA_MATRIXUDG_H

#include <iomanip>
#include <iostream>
#define MAX    100
#define INF    (~(0x1<<31))        // 无穷大(即0X7FFFFFFF)
using namespace std;

// 边的结构体
class EData {
public:
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重

public:
    EData() {}

    EData(char s, char e, int w) : start(s), end(e), weight(w) {}
};
class MatrixUDG {
private:
    char mVexs[MAX];    // 顶点集合
    int mVexNum;             // 顶点数
    int mEdgNum;             // 边数
    int mMatrix[MAX][MAX];   // 邻接矩阵

public:
    MatrixUDG(char vexs[], int vlen, int matrix[][9]);
    ~MatrixUDG();

    void dijkstra(int vs, int vexs[], int dist[]);
    void print();
};

/**
 * 创建图(用已提供的矩阵)
 * @param vexs 顶点数组
 * @param vlen 顶点数组的长度
 * @param matrix 矩阵(数据)
 */
MatrixUDG::MatrixUDG(char vexs[], int vlen, int matrix[][9]) {
    int i, j;

    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    // 初始化"顶点"
    for (i = 0; i < mVexNum; i++)
        mVexs[i] = vexs[i];

    // 初始化"边"
    for (i = 0; i < mVexNum; i++)
        for (j = 0; j < mVexNum; j++)
            mMatrix[i][j] = matrix[i][j];

    // 统计边的数目
    for (i = 0; i < mVexNum; i++)
        for (j = 0; j < mVexNum; j++)
            if (i != j && mMatrix[i][j] != INF)
                mEdgNum++;
    mEdgNum /= 2;
}

/**
 * 析构函数
 */
MatrixUDG::~MatrixUDG() {
}


/**
 * 打印矩阵队列图
 */
void MatrixUDG::print() {
    int i, j;

    cout << "Martix Graph:" << endl;
    for (i = 0; i < mVexNum; i++) {
        for (j = 0; j < mVexNum; j++)
            cout << setw(10) << mMatrix[i][j] << " ";
        cout << endl;
    }
}

/**
 * Dijkstra最短路径。即，统计图中"顶点vs"到其它各个顶点的最短路径。
 *
 * @param vs 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。(最开始的起始点)
 * @param prev 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 * @param dist 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 */
void MatrixUDG::dijkstra(int vs, int prev[], int dist[]) {
    int k;
    int min;
    int tmp;
    int flag[MAX];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。

    // 初始化
    for (int i = 0; i < mVexNum; i++) {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = mMatrix[vs][i]; // 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历mVexNum-1次；每次找出一个顶点的最短路径。
    for (int i = 1; i < mVexNum; i++) {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (int j = 0; j < mVexNum; j++) {
            if (flag[j] == 0 && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (int j = 0; j < mVexNum; j++) {
            tmp = (mMatrix[k][j] == INF ? INF : (min + mMatrix[k][j]));
            if (flag[j] == 0 && (tmp < dist[j])) {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    cout << "dijkstra(" << mVexs[vs] << "): " << endl;
    for (int i = 0; i < mVexNum; i++)
        cout << "  shortest(" << mVexs[vs] << ", " << mVexs[i] << ")=" << dist[i] << endl;
}

#endif //DIJKSTRA_MATRIXUDG_H
