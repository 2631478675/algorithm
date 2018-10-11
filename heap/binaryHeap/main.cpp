#include <iostream>
#include "MAXHeap.h"
#include "MINHeap.h"

int main()
{
    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int i, len=(sizeof(a)) / (sizeof(a[0])) ;
    MaxHeap<int>* tree=new MaxHeap<int>();
    MinHeap<int>* minTree = new MinHeap<int>();

//    cout << "== 依次添加: ";
//    for(i=0; i<len; i++)
//    {
//        cout << a[i] <<" ";
//        tree->insert(a[i]);
//    }
//
//    cout << "\n== 最 大 堆: ";
//    tree->print();
//
//    i=85;
//    tree->insert(i);
//    cout << "\n== 添加元素: " << i;
//    cout << "\n== 最 大 堆: ";
//    tree->print();
//
//    i=90;
//    tree->remove(i);
//    cout << "\n== 删除元素: " << i;
//    cout << "\n== 最 大 堆: ";
//    tree->print();
//    cout << endl;

    cout << "== 依次添加min: ";
    for(i=0; i<len; i++)
    {
        cout << a[i] <<" ";
        minTree->insert(a[i]);
    }

    cout << "\n== 最 min 堆: ";
    minTree->print();

    i=85;
    minTree->insert(i);
    cout << "\n== 添加元素: " << i;
    cout << "\n== 最 min 堆: ";
    minTree->print();

    i=90;
    minTree->deleteHeap(i);
    cout << "\n== 删除元素: " << i;
    cout << "\n== 最 min 堆: ";
    minTree->print();

    return 0;
}