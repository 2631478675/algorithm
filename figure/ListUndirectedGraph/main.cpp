#include <iostream>

using namespace std;
#define MAX 100
class MatrixUDG{
private:
    char mVexs[MAX]; //顶点集合
    int mVesNum; //顶点数
    int mEdgeNum; //边数
    int mMatrix[MAX][MAX]; //图的邻接矩阵
public:
    // 创建图(自己输入数据)
    MatrixUDG();
    // 创建图(用已提供的矩阵)
    MatrixUDG(char vexs[], int vlen, char edges[][2], int elen);
    ~MatrixUDG();


    void print();
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}