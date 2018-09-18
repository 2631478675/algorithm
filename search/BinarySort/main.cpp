#include <iostream>

/**
 * 关于二分查找法
 *二分查找法主要是解决在“一堆数中找出指定的数”这类问题。

 *而想要应用二分查找法，这“一堆数”必须有一下特征：

    存储在数组中
    有序排列
 *所以如果是用链表存储的，就无法在其上应用二分查找法了。（曽在面试被问二分查找法可以什么数据结构上使用：数组？链表？）

 *至于是顺序递增排列还是递减排列，数组中是否存在相同的元素都不要紧。不过一般情况，我们还是希望并假设数组是递增排列，数组中的元素互不相同。
 */
using namespace std;
int BinarySort(int *R,int value,int low,int high){
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (R[mid] == value)
        return mid+1;
    else if (R[mid] > value)
        return BinarySort(R, value, low, mid - 1);
    else
        return BinarySort(R, value, mid + 1, high);
}
int Partition(int *R,int low,int high){
    int pivot = R[low];
    while(low<high){
        while(R[high] >= pivot && low < high){
            high --;
        }
        swap(R[low],R[high]);
        while(R[low] <= pivot && low < high){
            low ++;
        }
        swap(R[low],R[high]);
    }
    return low;
}
void quickSort(int *R,int low,int high){
    if(low < high){
        int partition = Partition(R,low,high);
        quickSort(R,low,partition -1);
        quickSort(R,partition +1,high);
    }
}
int main() {
    int A[10] = {31,17,8,55,2,1,9,5,34,10};
    int len = sizeof(A)/ sizeof(int);
    quickSort(A,0,len -1);
    for(int i=0;i<len;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    int get = BinarySort(A,55,0,len -1);
    cout << "3 local is:"<< get <<endl;
    return 0;
}