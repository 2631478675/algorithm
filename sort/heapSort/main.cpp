#include <iostream>
/**
 * http://www.cnblogs.com/skywang12345/p/3602162.html
 */
using namespace std;

/**
 * 最大堆
 * @param R
 * @param i
 * @param len
 */
void HeapDown(int *R, int i, int len) {
    int child = i * 2 + 1;
    int current = i;
    for (; child < len; current = child, child = child * 2 + 1) {
        // it has rightChild and who bigger
        if (child + 1 < len && R[child] < R[child + 1]) {
            child++;
        }
        if (R[current] < R[child]) {
            swap(R[current], R[child]);
        } else {
            break;
        }
    }
}

/**
 * 最小堆
 * @param R
 * @param i
 * @param len
 */
void HeapUp(int *R,int i,int len){
    int child = 2*i+1;
    int current = i;
    for (; child < len; current = child, child = child * 2 + 1) {
        // it has rightChild and who bigger
        if (child + 1 < len && R[child] > R[child + 1]) {
            child++;
        }
        if (R[current] > R[child]) {
            swap(R[current], R[child]);
        } else {
            break;
        }
    }
}

void HeapBuild(int *R, int len) {
    //get the node who has children,
    int i = len / 2 - 1;
    for (; i >= 0; i--) {
        HeapUp(R, i, len);
    }
}

void HeapSort(int *R, int len) {
    for (int i = len - 1; i > 0; i--) {
        swap(R[0], R[i]);
        HeapUp(R, 0, i);
    }
}

int main() {
    int i;
    int a[] = {20, 30, 90, 40, 70, 110, 60, 10, 100, 50, 80};
    int ilen = (sizeof(a)) / (sizeof(a[0]));


    cout << "before sort:";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;


    HeapBuild(a, ilen);            // 升序排列
    cout << "build  heap:";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;




    HeapSort(a, ilen);
    cout << "after  sort:";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}