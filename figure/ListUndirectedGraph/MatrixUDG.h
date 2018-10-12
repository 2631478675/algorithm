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

public:
    MatrixUDG();

    ~MatrixUDG();

    void print();

    MatrixUDG(char *, int, char (*pString)[2], int);
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

    for(int i = 0; i < vexNum; i++){
        for(int j = 0; j < edgeNum; j++){
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

#endif //LISTUNDIRECTEDGRAPH_MATRIXUDG_H
