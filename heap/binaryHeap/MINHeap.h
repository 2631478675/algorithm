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


template<class T>
class MinHeap{
private: //仅限内部类调用
    T * heap; //堆中存储的数据
    int mSize;
    int mCapacity;  //堆的容量

    void filterUp(int);
    void filterDown(int,int);
public:
    MinHeap();
    MinHeap(int);
    ~ MinHeap();

    void print();
    int insert(T data);
    int deleteHeap(T data);
    int getIndex(T data);
};

/**
 * 无参构造函数
 * @tparam T
 */
template<class T>
MinHeap<T>::MinHeap() {
    new(this)MinHeap(30);
}

/**
 * 有参构造函数
 * @tparam T
 * @param capacity
 */
template<class T>
MinHeap<T>::MinHeap(int capacity) {
    mSize = 0;
    mCapacity = capacity;
    heap = new T[mCapacity];
}

/**
 * 析构函数
 * @tparam T
 */
template<class T>
MinHeap<T>::~MinHeap() {
    mCapacity = 0;
    mSize = 0;
    delete [] heap;
}

/**
 * 获取data在数组中的索引
 * @tparam T
 * @param data
 * @return
 */
template<class T>
int MinHeap<T>::getIndex(T data) {
    int index = 0;
    for(;index < mSize; index++){
        if(data == heap[index]){
            return index;
        }
    }
    return -1;  //堆中没有这个数据
}

template<class T>
void MinHeap<T>::filterUp(int start) {
    int current = start;
    int parent = (current-1) / 2;
    T valueOFCurrent = heap[current];

    for(;current > 0;){
        if(heap[parent] > heap[current]){
            swap(heap[parent],heap[current]);
            current = parent;
            parent = (current-1)/2;
        } else{
            break;
        }
    }

}

template<class T>
void MinHeap<T>::filterDown(int start, int end) {
    int current = start;
    int leftChildren = current*2 + 1;
    T valueOFCurrent = heap[start];

    while(leftChildren <= end){
          if(leftChildren + 1 <= end && heap[leftChildren] > heap[leftChildren+1]){
            leftChildren++;
          }else if(valueOFCurrent <= heap[leftChildren]){
            break;
          } else{
              swap(heap[current],heap[leftChildren]);
              current = leftChildren;
              leftChildren = current*2 +1;
          }
    }
}

template<class T>
int MinHeap<T>::insert(T data) {
//    cout << " ths msize is:" << mSize << "the mcapacity is :"<< mCapacity << endl;
    if(mSize == mCapacity){
        cout << "the heap is full";
        return -1;
    }
    heap[mSize] = data;
    filterUp(mSize);
    mSize++;
    return 0;
}

template<class T>
int MinHeap<T>::deleteHeap(T data) {
    if(mSize == 0){
        return -1;
    }
    int index = getIndex(data);
    if(index == -1){
        return -1;
    }
    heap[index] = heap[--mSize];
    filterDown(index,mSize-1);
    return 0;
}


template<class T>
void MinHeap<T>::print() {
    for (int i = 0; i < mSize ; ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
#endif //BINARYHEAP_MINHEAP_H
