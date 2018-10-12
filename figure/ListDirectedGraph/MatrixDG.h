//
// Created by I500042 on 10/12/2018.
//

#ifndef LISTDIRECTEDGRAPH_MATRIXDG_H
#define LISTDIRECTEDGRAPH_MATRIXDG_H
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
#define MAX 100

class MatrixDG {
private:
    char vexs[MAX];
    int vexNum;
    int edgeNum;
    int matrix[MAX][MAX];

    char readChar();

    int getPosition(char);

public:
    MatrixDG();

    ~MatrixDG();

    void print();

    MatrixDG(char *, int, char (*pString)[2], int);
};

char MatrixDG::readChar() {
    char ch;
    do {
        cin >> ch;
    } while (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));
    return ch;
}


int MatrixDG::getPosition(char ch) {
    for (int i = 0; i < vexNum; i++) {
        if (vexs[i] == ch) {
            return i;
        }
    }
    return -1;
}

MatrixDG::MatrixDG() {

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

    }
}

MatrixDG::~MatrixDG() {

}

void MatrixDG::print() {
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
MatrixDG::MatrixDG(char *vexsingle, int vlen, char (*edge)[2], int elen) {
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
    }
}
#endif //LISTDIRECTEDGRAPH_MATRIXDG_H
