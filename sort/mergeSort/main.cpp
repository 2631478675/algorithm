#include <iostream>

using namespace std;

void Merge(int *Array,int *L,int *R,int middle,int rmiddle){
    int l = 0,r = 0,k =0;
    while(l<middle && r<rmiddle){
        if(L[l]<R[r]){
            Array[k++] = L[l++];
        } else{
            Array[k++] = R[r++];
        }
    }
    //if : l<middle && r>rmiddle
    while (l < middle){
       Array[k++] = L[l++];
    }
    while (r < rmiddle){
        Array[k++] = R[r++];
    }
}
void mergeSort(int *Array,int n){
    if(n <2){
        return;
    }
    int middle = n/2;
    int *L,*R;
    L = new int[middle];
    R = new int [n-middle];
    for(int i=0;i<middle;i++){
        L[i] = Array[i];
    }
    for(int i=middle;i<n;i++){
        R[i-middle] =Array[i];
    }
    mergeSort(L,middle);
    mergeSort(R,n-middle);
    Merge(Array,L,R,middle,n-middle);
}
int main() {
    int A[] = {6,2,3,1,9,10,15,13,12,17};
    mergeSort(A,10);
    for(int i =0 ;i < 10;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}