#include <iostream>
using namespace std;

void heapify (int a[], int n, int i) {
    int head = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && a[l] > a[head])
        head = l;
    if(r < n && a[r] > a[head])
        head = r;

    if(head != i) {
        swap (a[i], a[head]);
        heapify (a, n, head);
    }
}
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void show(int a[], int n) {
    for(int i = 0 ;i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
int main () {
    int a[]{0,4,3,6,5,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);

    heapSort(a, n);
    show(a, n);

    return 0;
}