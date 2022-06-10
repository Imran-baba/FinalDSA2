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

void MergeSort(int a[], int low, int high) {
    
    if(low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        merge(a, low, mid, high); 
    }

}

int main() {
    int a[] {3, 5, 4, 1, 6, 7, 2, 9, 8};
    int n{sizeof(a)/sizeof(a[0])};

    MergeSort(a,0,n-1);
    show(a,n);

}