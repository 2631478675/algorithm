#include <iostream>

using namespace std;
/**
 * http://www.cnblogs.com/skywang12345/p/3602162.html
 * @param R
 * @param i
 * @param len
 */
void HeapDown(int *R, int i, int len) {
    int child = i * 2 + 1;
    int current = i;
    for (; child < len ; current = child , child = child * 2 + 1) {
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

void HeapBuild(int *R, int len) {
    //get the node who has children,
    int i = len / 2 - 1;
    for (; i >= 0; i--) {
        HeapDown(R, i, len);
    }
    for (i = len - 1; i > 0; i--)
    {
        // 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
        swap(R[0], R[i]);
        // 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
        // 即，保证a[i-1]是a[0...i-1]中的最大值。
        HeapDown(R, 0, i);
    }
}

int main() {
    int i;
    int a[] = {20,30,90,40,70,110,60,10,100,50,80};
    int ilen = (sizeof(a)) / (sizeof(a[0]));
    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;
    HeapBuild(a, ilen);            // 升序排列
    //heapSortDesc(a, ilen);        // 降序排列
    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}