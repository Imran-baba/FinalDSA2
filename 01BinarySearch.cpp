#include <iostream>
using namespace std;

int binSearch(int a[], int n, int key) {
    int low{0}, high{n-1};
    while(high >= low) {
        int mid = (low + high) /2;
        if (a[mid] == key) return mid+1;
        if (key > a[mid]) low = mid+1;
        if (key < a[mid]) high = mid-1;
    }
    return -1;
}
int binSearch(int a[], int low, int high, int key) {
    if(low > high) return -1;

    int mid = (low + high) / 2;
    
    if (a[mid] == key) return mid+1;
    else if (a[mid] > key) binSearch (a, low, mid-1, key);
    else binSearch (a, mid+1, high, key);
}


int main() {

    int a[]  {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);

    for (int i = 0 ; i < 10; i++)
    cout << i  << ": " <<  binSearch(a,n,i) << '\n';


    return 0;
}