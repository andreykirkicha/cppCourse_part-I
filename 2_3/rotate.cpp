#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void rotate(int a[], unsigned size, int shift) {
    int j = 0;
    
    while (j++ < shift) {
        unsigned i = 0;
        while (i < size - 1) {
            swap(&a[i], &a[i + 1]);
            i++;
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    rotate(a, 5, 1);

    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}