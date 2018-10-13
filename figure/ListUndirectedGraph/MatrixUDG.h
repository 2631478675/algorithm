//
// Created by 刘元林 on 2018/10/11.
//

#ifndef LISTUNDIRECTEDGRAPH_MATRIXUDG_H
#define LISTUNDIRECTEDGRAPH_MATRIXUDG_H
/**
 * 邻接矩阵无向图 Adjacent matrix undirected graph
 */
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
#define MAX 100

class MatrixUDG {
private:
    char vexs[MAX];
    int vexNum;
    int edgeNum;
    int matrix[MAX][MAX];

    char readChar();

    int getPosition(char);

    // 返回顶点v的第一个邻接顶点的索引，失败则返回-1
    int firstVertex(int v);

    // 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
    int nextVertex(int v, int w);

    // 深度优先搜索遍历图的递归实现
    void DFS(int i, int *visited);

public:
    MatrixUDG();

    ~MatrixUDG();

    void print();

    MatrixUDG(char *, int, char (*pString)[2], int);

    // 深度优先搜索遍历图
    void DFS();

    // 广度优先搜索（类似于树的层次遍历）
    void BFS();
};

char MatrixUDG::readChar() {
    char ch;
    do {
        cin >> ch;
    } while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));
    return ch;
}


int MatrixUDG::getPosition(char ch) {
    for (int i = 0; i < vexNum; i++) {
        if (vexs[i] == ch) {
            return i;
        }
    }
    return -1;
}

MatrixUDG::MatrixUDG() {

    cout << "input the vexNum :";
    cin >> vexNum;
    cout << "input the edgeNum :";
    cin >> edgeNum;

    // commute the data rationality

    if (vexNum <= 0 || edgeNum <= 0 || (edgeNum > vexNum * (vexNum - 1))) {
        cout << "unreasonable data entry" << endl;
        return;
    }

    cout << "input the vexs: " << endl;
    for (int i = 0; i < vexNum; i++) {
        cout << "vertex(" << i << "): ";
        vexs[i] = readChar();
    }

    cout << "input data to create edge:" << endl;
    for (int i = 0; i < edgeNum; i++) {

        cout << "edge(" << i << "): ";
        char ch1 = readChar();
        char ch2 = readChar();

        int ch1Position = getPosition(ch1);
        int ch2Position = getPosition(ch2);

        matrix[ch1Position][ch2Position] = 1;
        matrix[ch2Position][ch1Position] = 1;

    }
}

MatrixUDG::~MatrixUDG() {

}

void MatrixUDG::print() {
    for (int i = 0; i < vexNum; i++) {
        for (int j = 0; j < vexNum; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 *
 * @param string : vexs
 * @param vlen : the size of vexs
 * @param pString : edges
 * @param elen : the size of edges
 */
MatrixUDG::MatrixUDG(char *vexsingle, int vlen, char (*edge)[2], int elen) {
    vexNum = vlen;
    edgeNum = elen;

    for (int i = 0; i < vexNum; i++) {
        for (int j = 0; j < edgeNum; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < vexNum; i++) {
        vexs[i] = vexsingle[i];
    }

    for (int i = 0; i < edgeNum; i++) {

        int ch1Position = getPosition(edge[i][0]);
        int ch2Position = getPosition(edge[i][1]);

        matrix[ch1Position][ch2Position] = 1;
        matrix[ch2Position][ch1Position] = 1;
    }
}

/**
 * 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
 * @param v
 * @param w
 * @return
 */

int MatrixUDG::nextVertex(int v, int w) {
    int i;

    if (v < 0 || v > (vexNum - 1) || w < 0 || w > (vexNum - 1))
        return -1;

    for (i = w + 1; i < vexNum; i++)
        if (matrix[v][i] == 1)
            return i;

    return -1;
}

/**
 * 返回顶点v的第一个邻接顶点的索引，失败则返回-1
 * 根据data的索引v，去寻找它的
 * @param v
 * @return
 */
int MatrixUDG::firstVertex(int v) {
    int i;

    if (v < 0 || v > (vexNum - 1))
        return -1;

    for (i = 0; i < vexNum; i++)
        if (matrix[v][i] == 1)
            return i;

    return -1;
}

/**
 * 深度优先搜索的递归实现
 * @param i：将要访问的data的索引
 * @param visited : 顶点标记为0或为1
 */
void MatrixUDG::DFS(int i, int *visited) {
    int w;

    visited[i] = 1;
    cout << vexs[i] << " ";
    // 遍历该顶点的所有邻接顶点。若是没有访问过，那么继续往下走
    for (w = firstVertex(i); w >= 0;) {
        if (!visited[w])
            DFS(w, visited);
        w = nextVertex(i, w);
    }
}

/**
 * 深度优先遍历（Depth-First-Search）
 */
void MatrixUDG::DFS() {
    int visited[MAX];       // 顶点访问标记，如果顶点没被访问，则设置visited[i] = 0;否则为1

    // 初始化所有顶点都没有被访问
    for (int i = 0; i < vexNum; i++)
        visited[i] = 0;

    cout << "DFS: ";
    for (int i = 0; i < vexNum; i++) {
        if (!visited[i])
            DFS(i, visited);
    }
    cout << endl;
}


/**
 * 使用到了队列
 */
void MatrixUDG::BFS() {
    int visited[vexNum];
    int head = 0 , rear = 0;     // 辅组队列
    int queue[MAX];

    for (int i = 0; i < vexNum; i++) {
        visited[i] = 0;
    }

    cout << "BFS: ";
    for (int i = 0; i < vexNum; i++) {
        if (visited[i] == 0) {
            cout << vexs[i] << " ";
            visited[i] = 1;
            queue[rear++] = i;
        }
        while(head != rear){
            int j = queue[head++];
            for(int k = firstVertex(j); k >= 0; k = nextVertex(j, k)){
                if (!visited[k])
                {
                    visited[k] = 1;
                    cout << vexs[k] << " ";
                    queue[rear++] = k;
                }
            }
        }
    }
    cout << endl;
}





///*
// * 广度优先搜索（类似于树的层次遍历）
// */
//void MatrixUDG::BFS()
//{
//    int head = 0;
//    int rear = 0;
//    int queue[MAX];     // 辅组队列
//    int visited[MAX];   // 顶点访问标记
//    int i, j, k;
//
//    for (i = 0; i < vexNum; i++)
//        visited[i] = 0;
//
//    cout << "BFS: ";
//    for (i = 0; i < vexNum; i++)
//    {
//        if (!visited[i])
//        {
//            visited[i] = 1;
//            cout << vexs[i] << " ";
//            queue[rear++] = i;  // 入队列
//        }
//        while (head != rear)
//        {
//            j = queue[head++];  // 出队列
//            for (k = firstVertex(j); k >= 0; k = nextVertex(j, k)) //k是为访问的邻接顶点
//            {
//                if (!visited[k])
//                {
//                    visited[k] = 1;
//                    cout << vexs[k] << " ";
//                    queue[rear++] = k;
//                }
//            }
//        }
//    }
//    cout << endl;
//}
#endif //LISTUNDIRECTEDGRAPH_MATRIXUDG_H
