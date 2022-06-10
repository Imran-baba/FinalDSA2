#include <iostream>
#include <limits.h>
using namespace std;

int Partition(int a[], int l, int h) {
    int piv = a[l];
    int i = l, j = h;
    do {
        do { i++; } while (a[i] <= piv);
        do { j--; } while (a[j] > piv);
        if( i < j ) swap (a[i], a[j]);
    } while (i < j);

    swap(a[l], a[j]);
    return j;
}

void QuickSort(int a[], int low, int high) {
    if(low < high) {
        QuickSort(a, low, Partition(a, low, high));
        QuickSort(a, Partition(a, low,high)+1, high);
    }
}

void show(int a[], int n) {
    for(int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    cout << '\n';

    return;
}

int main() {
    int a[] {3, 5, 4, 1, 6, 7, 2, 8, INT_MAX};
    int n { sizeof(a)/sizeof(a[0]) };

    QuickSort(a, 0, n-1);
    show(a, n-1);

    return 0;
}