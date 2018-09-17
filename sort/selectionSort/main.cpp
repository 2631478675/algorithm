#include <iostream>

using namespace std;

/**
 * 每次选择剩下的最小的，然后放到相应的位置
 * @return
 */
void selectionSort(int *R, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (R[min] > R[j]) {
                min = j;
            }
        }
        swap(R[i], R[min]);
    }
}

int main() {
    int i;
    int a[] = {20, 40, 30, 10, 60, 50};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "before sort:";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    selectionSort(a, ilen);

    cout << "after  sort:";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}