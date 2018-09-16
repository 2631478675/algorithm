#include <iostream>

using namespace std;
void BubbleSort(int *R,int n){
    for(int i= 1; i<n;i++){
        for(int j =0 ;j<n-1;j++){
            if(R[j] > R[j+1]){
                swap(R[j],R[j+1]);
            }

        }
    }
}
int main() {
    int A[10] = {3,7,8,5,2,1,9,5,4,0};
    BubbleSort(A, sizeof(A)/ sizeof(int));
    for(int i=0;i<10;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}