//
// Created by I500042 on 10/12/2018.
//

#ifndef ADJACENCYTUG_TABLEUNDIRECTEDGRAPH_H
#define ADJACENCYTUG_TABLEUNDIRECTEDGRAPH_H

#include <iomanip>
#include <iostream>
#include <vector>

#define MAX 100
using namespace std;

class TableUndirectedGraph {
private: // 内部类

    // 邻接表中表对应的链表的顶点
    class EdgeNode {
    public:
        int ivex;           // 该边所指向的顶点的位置
        EdgeNode *nextEdge;    // 指向下一条弧的指针
    };

    // 邻接表中表的顶点
    class VexNode {
    public:
        char data;          // 顶点信息
        EdgeNode *firstEdge;   // 指向第一条依附该顶点的弧
    };

private: // 私有成员
    int mVexNum;             // 图的顶点的数目
    int mEdgNum;             // 图的边的数目
    VexNode mVexs[MAX];

public:
    TableUndirectedGraph();

    TableUndirectedGraph(char vexs[], int vlen, char edges[][2], int elen);

    ~TableUndirectedGraph();

    void print();

    void DFS();

    void DFS(int, int *);

    void BFS();

private:
    // 读取一个输入字符
    char readChar();

    // 返回ch的位置
    int getPosition(char ch);

    // 将node节点链接到list的最后
    void linkLast(EdgeNode *list, EdgeNode *node);
};

char TableUndirectedGraph::readChar() {
    char ch;
    do {
        cin >> ch;
    } while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));

    return ch;
}

int TableUndirectedGraph::getPosition(char ch) {
    for (int i = 0; i < mVexNum; i++) {
        if (mVexs[i].data == ch) {
            return i;
        }
    }
    return -1;
}

void TableUndirectedGraph::linkLast(TableUndirectedGraph::EdgeNode *list, TableUndirectedGraph::EdgeNode *node) {
    EdgeNode *p = list;
    while (p->nextEdge) {
        p = p->nextEdge;
    }
    p->nextEdge = node;
}

TableUndirectedGraph::TableUndirectedGraph() {

    cout << "input vertex number: ";
    cin >> mVexNum;
    cout << "input edge number: ";
    cin >> mEdgNum;
    if (mVexNum < 1 || mEdgNum < 1 || (mEdgNum > (mVexNum * (mVexNum - 1)))) {
        cout << "input error: invalid parameters!" << endl;
        return;
    }

    cout << "initialization vertex : " << endl;
    for (int i = 0; i < mVexNum; i++) {
        cout << "vertex(" << i << "): ";
        mVexs[i].data = readChar();
        mVexs[i].firstEdge = NULL;
    }


    for (int i = 0; i < mEdgNum; i++) {
        cout << "initalization edge" << i << ": " << endl;
        char vex1 = readChar();
        char vex2 = readChar();

        int indexOfvex1 = getPosition(vex1);
        int indexOfvex2 = getPosition(vex2);

        EdgeNode *edgeNode1 = new EdgeNode();
        edgeNode1->ivex = indexOfvex1;
        EdgeNode *edgeNode2 = new EdgeNode();
        edgeNode2->ivex = indexOfvex2;

        if (mVexs[indexOfvex1].firstEdge == NULL) {
            mVexs[indexOfvex1].firstEdge = edgeNode2;
        } else {
            linkLast(mVexs[indexOfvex1].firstEdge, edgeNode2);
        }
        if (mVexs[indexOfvex2].firstEdge == NULL) {
            mVexs[indexOfvex2].firstEdge = edgeNode1;
        } else {
            linkLast(mVexs[indexOfvex2].firstEdge, edgeNode1);
        }
    }

}

TableUndirectedGraph::TableUndirectedGraph(char vexs[], int vlen, char edges[][2], int elen) {
    mEdgNum = elen;
    mVexNum = vlen;

    for (int i = 0; i < mVexNum; i++) {
        mVexs[i].data = vexs[i];
        mVexs[i].firstEdge = NULL;
    }
    for (int i = 0; i < mEdgNum; i++) {
        EdgeNode *edgeNode1 = new EdgeNode();
        EdgeNode *edgeNode2 = new EdgeNode();

        int nodePosition1 = getPosition(edges[i][0]);
        int nodePosition2 = getPosition(edges[i][1]);

        edgeNode1->ivex = nodePosition2;
        edgeNode1->nextEdge = NULL;
        edgeNode2->ivex = nodePosition1;
        edgeNode2->nextEdge = NULL;

        if (mVexs[nodePosition1].firstEdge == NULL) {
            mVexs[nodePosition1].firstEdge = edgeNode1;
        } else {
            linkLast(mVexs[nodePosition1].firstEdge, edgeNode1);
        }
        if (mVexs[nodePosition2].firstEdge == NULL) {
            mVexs[nodePosition2].firstEdge = edgeNode2;
        } else {
            linkLast(mVexs[nodePosition2].firstEdge, edgeNode2);
        }
    }
}

void TableUndirectedGraph::print() {
    for (int i = 0; i < mVexNum; i++) {
        cout << "[ " << mVexs[i].data << " ]";
        EdgeNode *p = mVexs[i].firstEdge;
        while (p) {
            cout << "->" << p->ivex;
            p = p->nextEdge;
        }
        cout << endl;
    }
}

void TableUndirectedGraph::DFS() {
    int visited[mVexNum];
    for (int i = 0; i < mVexNum; i++) {
        visited[i] = 0;
    }

    cout << "DFS : ";
    for (int i = 0; i < mVexNum; i++) {
        if (visited[i] == 0)
            DFS(i, visited);
    }
    cout << endl;
}

void TableUndirectedGraph::DFS(int index, int *visited) {
    cout << mVexs[index].data << " ";
    visited[index] = 1;
    EdgeNode *node = new EdgeNode();
    node = mVexs[index].firstEdge;
    while (node != NULL) {
        if (visited[node->ivex] == 0)
            DFS(node->ivex, visited);
        node = node->nextEdge;
    }
}

/**
 * 使用到了队列
 */
void TableUndirectedGraph::BFS() {
    int visited[mVexNum];
    int head = 0 , rear = 0;     // 辅组队列
    int queue[MAX];
    EdgeNode *node = new EdgeNode();

    for (int i = 0; i < mVexNum; i++) {
        visited[i] = 0;
    }

    cout << "BFS : ";
    for (int i = 0; i < mVexNum; i++) {
        if (visited[i] == 0) {
            cout << mVexs[i].data << " ";
            visited[i] = 1;
            queue[rear++] = i;
        }
        while(head != rear){
            int j = queue[head++];
            node = mVexs[j].firstEdge;
            while (node != NULL) {
                if (visited[node->ivex] == 0)
                    cout << mVexs[node->ivex].data << " ";
                    visited[node->ivex] = 1;
                    queue[rear++] = mVexs[node->ivex].data;
                node = node->nextEdge;
            }
        }
    }
    cout << endl;
}

#endif //ADJACENCYTUG_TABLEUNDIRECTEDGRAPH_H
