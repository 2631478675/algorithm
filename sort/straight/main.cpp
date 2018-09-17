#include <iostream>

using namespace std;

void straight(int *R, int len) {
    int i, j, k;
    for (i = 1; i < len; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (R[j] < R[i]) {
                break;
            }
        }
        if (j != i - 1) {
            for (k = i; k > j + 1; k--) {
                swap(R[k], R[k - 1]);
            }
        }
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
    straight(a, ilen);

    cout << "after  sort:";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}