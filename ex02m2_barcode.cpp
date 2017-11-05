#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int bc[31][31] = {};

int barcode(int n, int m, int k){
    if(n < 0 || k < 0 || n < k+1 || n > m*(k+1))
        return 0;
    if(bc[n][k] != 0)
        return bc[n][k];
    else if(k == 0 || n == k+1)
        bc[n][k] = 1;
    else {
        for(int i = 1; i <= m; i++){
            bc[n][k] += barcode(n-i, m, k-1);
        }
    }
    return bc[n][k];
}

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    cout << barcode(n,m,k);

    return 0;
}
