#include <iostream>
using namespace std;

void show(int a[], int n) {
    for(int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    cout << '\n';

    return;
}

void merge(int a[], int beg, int mid, int end) {
    int i = beg, k = beg, j = mid+1;

    int temp[100]{0};

    while(i <= mid && j <= end) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else 
            temp[k++] = a[j++];
    } 
    for(; i<=mid; i++)
        temp[k++] = a[i];
    for(; j <= end; j++)
        temp[k++] = a[j];
    
    for(i = beg; i<= end; i++)
        a[i] = temp[i];

}

void MergeSort(int a[], int n) {
    int p, l, h, mid, i;

    for(p = 2; p <= n; p *= 2 ) {
        for(i = 0; i+p-1 < n; i+=p) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;

            merge(a, l, mid, h);
        }
        if(n-i > p/2) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;

            merge(a, l, mid, h);
        }
    }
    if(p/2 < n) {
        merge(a, 0, p/2-1, n-1);
    }

    return;

}


int main() {
    int a[] {3, 5, 4, 1, 6, 7, 8};
    int n{sizeof(a)/sizeof(a[0])};

    MergeSort(a,n);
    show(a,n);

}