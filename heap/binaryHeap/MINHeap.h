//
// Created by 刘元林 on 2018/10/10.
//
/**
 * 创建最小堆
 * 添加元素
 * 删除元素
 */
#ifndef BINARYHEAP_MINHEAP_H
#define BINARYHEAP_MINHEAP_H

#include <iostream>

using namespace std;

template<class T>
class MaxHeap {
private:
    T *mHeap;        // 数据
    int mCapacity;    // 总的容量
    int mSize;        // 实际容量

private:
    // 最大堆的向下调整算法
    void filterDown(int start, int end);

    // 最大堆的向上调整算法(从start开始向上直到0，调整堆)
    void filterUp(int start);

public:
    MaxHeap();

    MaxHeap(int capacity);

    ~MaxHeap();

    // 返回data在二叉堆中的索引（索引从0开始）
    int getIndex(T data);

    // 删除最大堆中的data
    int remove(T data);

    // 将data插入到二叉堆中
    int insert(T data);

    // 打印二叉堆
    void print();
};

/**
 * 构造函数
 * @tparam T
 */
template<class T>
MaxHeap<T>::MaxHeap() {
    new(this)MaxHeap(30);
}

template<class T>
MaxHeap<T>::MaxHeap(int capacity) {
    mSize = 0;
    mCapacity = capacity;
    mHeap = new T[mCapacity];
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
MaxHeap<T>::~MaxHeap() {
    mSize = 0;
    mCapacity = 0;
    delete[] mHeap;
}

/**
 * 最大堆的向下调整算法
 * @tparam T
 * @param start 被下调节点的起始位置(一般为0，表示从第1个开始)
 * @param end 截至范围(一般为数组中最后一个元素的索引)
 */
template<class T>
void MaxHeap<T>::filterDown(int start, int end) {
    int current = start;
    int left = current * 2 + 1;
    T tmp = mHeap[current]; // ? ? ?

    while (left <= end) {
        if (left < end && mHeap[left] < mHeap[left + 1]) {
            left++;
        }
        if (tmp >= mHeap[left]) {
            break;
        } else {
            mHeap[current] = mHeap[left];
            current = left;
            left = 2 * left + 1;
        }
    }
    mHeap[current] = tmp;
}

/**
 * 最大堆的向上调整算法
 * @tparam T
 * @param start 被上调节点的起始位置(一般为数组中最后一个元素的索引)
 */
template<class T>
void MaxHeap<T>::filterUp(int start) {
    int current = start;            // 当前节点(current)的位置
    int parent = (current - 1) / 2;        // 父(parent)结点的位置
    T tmp = mHeap[current];        // 当前节点(current)的大小

    while (current > 0) {
        if (mHeap[parent] >= tmp)
            break;
        else {
            mHeap[current] = mHeap[parent];
            current = parent;
            parent = (parent - 1) / 2;
        }
    }
    mHeap[current] = tmp;
}


/**
 * 将data插入到二叉堆中
 * @tparam T
 * @param data
 * @return
 */
template<class T>
int MaxHeap<T>::insert(T data) {
    // 如果"堆"已满，则返回
    if (mSize == mCapacity)
        return -1;

    mHeap[mSize] = data;        // 将"数组"插在表尾
    filterUp(mSize);    // 向上调整堆
    mSize++;                    // 堆的实际容量+1

    return 0;
}

/**
 * 删除数据data
 * @tparam T
 * @param data
 * @return
 */
template<class T>
int MaxHeap<T>::remove(T data) {
    int index;
    // 如果"堆"已空，则返回-1
    if (mSize == 0)
        return -1;

    // 获取data在数组中的索引
    index = getIndex(data);
    if (index == -1)
        return -1;

    mHeap[index] = mHeap[--mSize];    // 用最后元素填补
    filterDown(index, mSize - 1);        // 从index位置开始自上向下调整为最大堆

    return 0;
}


/**
 * 返回data在二叉堆中的索引
 * @tparam T
 * @param data
 * @return
 */
template<class T>
int MaxHeap<T>::getIndex(T data) {
    for (int i = 0; i < mSize; i++)
        if (data == mHeap[i]) {
            return i;
        }
    return -1;
}

/**
 * 打印二叉堆
 * @tparam T
 */
template<class T>
void MaxHeap<T>::print() {
    for (int i = 0; i < mSize; i++)
        cout << mHeap[i] << " ";
}

#endif //BINARYHEAP_MINHEAP_H
