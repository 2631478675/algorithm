#include <iostream>

using namespace std;
void ShellSort(int *R, int len) {
    int gap, j;
    for (gap = len / 2; gap > 0; gap /= 2) {
        for (int i = 0; i < gap; i++) {
            for (j = i + gap; j < len; j += gap) {
                if (R[j] < R[j - gap]) {
                    int tmp = R[j];
                    int k = j - gap;
                    while(k >= 0 && R[k] >tmp){
                        R[k+gap] = R[k];
                        k -=gap;
                    }
                    R[k + gap] = tmp;
                }
            }
        }
    }
}

int main() {

    int a[] = {70,30,40,10,80,20,90,100,75,60,45};
    cout<<"Before Sort: ";
    for(int i=0; i<11; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    ShellSort(a, 11);
    cout<<"After Sort: ";
    for(int i=0; i<11; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}