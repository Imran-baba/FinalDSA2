#include <iostream>
#define size 2
using namespace std;

void MatMul(int a[][size], int b[][size], int c[][size]) {
    
    int i, j, k;
    
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++) 
            for(k = 0; k < size; k++)
                c[i][j] += a[i][k]*b[k][j];

    return;
}

int main() {
    int a[][size]{
        {2,2},
        {2,2}
    };
    int b[][size]{
        {2,2},
        {2,2}
    };

    int c[size][size]{0};
    MatMul(a,b,c);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            cout << c[i][j] << ' ';
        cout << "\n";
    }

    return 0;
}