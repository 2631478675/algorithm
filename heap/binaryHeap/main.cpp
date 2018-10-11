#include <iostream>
#include "MAXHeap.h"
#include "MINHeap.h"

//int main()
//{
//    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
//    int i, len=(sizeof(a)) / (sizeof(a[0])) ;
//    MaxHeap<int>* tree=new MaxHeap<int>();
//    MinHeap<int>* minTree = new MinHeap<int>();
//
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
//
//    cout << "insert min: ";
//    for(i=0; i<len; i++)
//    {
//        cout << a[i] <<" ";
//        minTree ->insert(a[i]);
//    }
//
//    cout << "\n== original min heap: ";
//    minTree->print();
//
//    i=15;
//    minTree->insert(i);
//    cout << "\n== insert data: " << i;
//    cout << "\n== 最 min 堆: ";
//    minTree->print();
//
//    i=10;
//    minTree->deleteHeap(i);
//    cout << "\n== 删除元素: " << i;
//    cout << "\n== 最 min 堆: ";
//    minTree->print();
//
//    return 0;
//}
int main()
{
    int a[] = {80, 40, 30, 60, 90, 70, 10, 50, 20};
    int i, len=(sizeof(a)) / (sizeof(a[0])) ;
    MinHeap<int>* tree=new MinHeap<int>();

    cout << "== 依次添加: ";
    for(i=0; i<len; i++)
    {
        cout << a[i] <<" ";
        tree->insert(a[i]);
    }

    cout << "\n== 最 小 堆: ";
    tree->print();

    i=15;
    tree->insert(i);
    cout << "\n== 添加元素: " << i;
    cout << "\n== 最 小 堆: ";
    tree->print();

    i=10;
    tree->deleteHeap(i);
    cout << "\n== 删除元素: " << i;
    cout << "\n== 最 小 堆: ";
    tree->print();
    cout << endl;

    return 0;
}