#include <iostream>
#include "test.h"

using namespace std;
static int arr[]= {1,5,4,3,2,6};
#define TBL_size(a) ((sizeof(a))/(sizeof(a[0])))
int main() {
    int len;
    len = TBL_size(arr);

    BSTree<int> *tree = new BSTree<int>();

    cout << "insert: ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
        tree->insert(arr[i]);
    }

    cout << endl;
    cout << "traversing preOrder: ";
    tree->preOrder();


    cout << endl;
    cout << "traversing midOrder: ";
    tree->midOrder();
    return 0;
}