#include <iostream>

using namespace std;


int partition(int *Array,int l,int r){
    int pivot = Array[l];
    while(l<r){
        while(l<r && Array[r] >= pivot){
            r--;
        }
        swap(Array[r],Array[l]);
        while (l<r && Array[l] <= pivot){
            l++;
        }
        swap(Array[r],Array[l]);
    }
    return l;
}
void quickSort(int *Array ,int l,int r){
    if(l < r){
        int pivot = partition(Array,l,r);
        quickSort(Array,l,pivot-1);
        quickSort(Array,pivot+1,r);
    }
}

int main() {

    int A[10] = {3,7,8,5,2,1,9,5,4,0};
    quickSort(A,0,9);
    for(int i=0;i<10;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}