#include <iostream>

using namespace std;

int partition(int *Arr,int l,int r){
    int pivot = Arr[l];
    while(l<r){
        while(l<r && Arr[r] >= pivot){
            r--;
        }
        swap(Arr[r],Arr[l]);
        while (l<r && Arr[l] <= pivot){
            l++;
        }
        swap(Arr[r],Arr[l]);
    }
    return l;
}
void quickSort(int *Arr, int l, int r) {
    if (l < r) {
        int pivot = partition(Arr, l, r);
        quickSort(Arr, l,pivot -1);
        quickSort(Arr,pivot + 1,r);
    }
}

int main() {
    int arr[10];
    cout << "请输入10个数字" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, 9);
    cout << "使用快速排序对数组中数字进行从小到大排序:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}