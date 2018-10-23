//
// Created by 刘元林 on 2018/10/23.
//

#ifndef KRUSKAL_MATRIXUDG_H
#define KRUSKAL_MATRIXUDG_H
#include <iomanip>
#include <iostream>
using namespace std;
#define MAX    100
#define INF    (~(0x1<<31))        // 无穷大(即0X7FFFFFFF)
class EData
{
public:
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重

public:
    EData(){}
    EData(char s, char e, int w):start(s),end(e),weight(w){}
};
class MatrixUDG{
private:
    char mVexs[MAX];    // 顶点集合
    int mVexNum;             // 顶点数
    int mEdgNum;             // 边数
    int mMatrix[MAX][MAX];   // 邻接矩阵

public:
    // 创建图(自己输入数据)
    MatrixUDG();
    // 创建图(用已提供的矩阵)
    //MatrixUDG(char vexs[], int vlen, char edges[][2], int elen);
    MatrixUDG(char vexs[], int vlen, int matrix[][9]);
    ~MatrixUDG();

    void kruskal();

    // 打印矩阵队列图
    void print();
private:
    int getPosition(char ch);
    // 获取图中的边
    EData* getEdges();
    // 对边按照权值大小进行排序(由小到大)
    void sortEdges(EData* edges, int elen);
    // 获取i的终点
    int getEnd(int vends[], int i);

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


/*
 * 返回ch在mMatrix矩阵中的位置
 */
int MatrixUDG::getPosition(char ch)
{
    int i;
    for(i=0; i<mVexNum; i++)
        if(mVexs[i]==ch)
            return i;
    return -1;
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

/*
 * 获取图中的边
 */
EData* MatrixUDG::getEdges()
{
    int i,j;
    int index=0;
    EData *edges;

    edges = new EData[mEdgNum];
    for (i=0; i < mVexNum; i++)
    {
        for (j=i+1; j < mVexNum; j++)
        {
            if (mMatrix[i][j]!=INF)
            {
                edges[index].start  = mVexs[i];
                edges[index].end    = mVexs[j];
                edges[index].weight = mMatrix[i][j];
                index++;
            }
        }
    }

    return edges;
}
/*
 * 对边按照权值大小进行排序(由小到大)
 */
void MatrixUDG::sortEdges(EData* edges, int elen)
{
    int i,j;

    for (i=0; i<elen; i++)
    {
        for (j=i+1; j<elen; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                // 交换"边i"和"边j"
                swap(edges[i], edges[j]);
            }
        }
    }
}
/*
 * 获取i的终点
 */
int MatrixUDG::getEnd(int vends[], int i)
{
    while (vends[i] != 0)
        i = vends[i];
    return i;
}
/*
 * 克鲁斯卡尔（Kruskal)最小生成树
 */
void MatrixUDG::kruskal()
{
    int i,m,n,p1,p2;
    int length;
    int index = 0;          // rets数组的索引
    int vends[MAX]={0};     // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。
    EData rets[MAX];        // 结果数组，保存kruskal最小生成树的边
    EData *edges;           // 图对应的所有边

    // 获取"图中所有的边"
    edges = getEdges();
    // 将边按照"权"的大小进行排序(从小到大)
    sortEdges(edges, mEdgNum);

    for (i=0; i<mEdgNum; i++)
    {
        p1 = getPosition(edges[i].start);      // 获取第i条边的"起点"的序号
        p2 = getPosition(edges[i].end);        // 获取第i条边的"终点"的序号

        m = getEnd(vends, p1);                 // 获取p1在"已有的最小生成树"中的终点
        n = getEnd(vends, p2);                 // 获取p2在"已有的最小生成树"中的终点
        // 如果m!=n，意味着"边i"与"已经添加到最小生成树中的顶点"没有形成环路
        if (m != n)
        {
            vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
            rets[index++] = edges[i];           // 保存结果
        }
    }
    delete[] edges;

    // 统计并打印"kruskal最小生成树"的信息
    length = 0;
    for (i = 0; i < index; i++)
        length += rets[i].weight;
    cout << "Kruskal=" << length << ": ";
    for (i = 0; i < index; i++)
        cout << "(" << rets[i].start << "," << rets[i].end << ") ";
    cout << endl;
}
#endif //KRUSKAL_MATRIXUDG_H
