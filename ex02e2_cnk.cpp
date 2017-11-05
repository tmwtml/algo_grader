#include <iostream>
#include <stdio.h>

using namespace std;

int c[31][31] = {};

int main()
{
    int n,k;
    cin >> n >> k;

    for(int i = 0; i <= n; i++){
        c[i][0] = 1;
        c[i][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
            if(i == n && j == k){
                cout << c[n][k];
                return 0;
            }
        }
    }

    return 0;
}
