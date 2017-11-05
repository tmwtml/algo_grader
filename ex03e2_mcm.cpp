#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, x;
    scanf("%d", &n);

    int s[n+1] = {};
    int m[n][n] = {};

    for(int i = 0; i <= n; i++){
        scanf("%d", &x);
        s[i] = x;
    }

    for(int i = 0; i < n-1; i++){
        m[i][i] = 0;
        m[i][i+1] = s[i]*s[i+1]*s[i+2];
    }
    m[n-1][n-1] = 0;

    for(int l = 2; l < n; l++){
        for(int i = 0; i < n-l; i++){
            int minm = 1000000;
            for(int j = i; j < i+l; j++){
                int mm = m[i][j] + m[j+1][i+l] + s[i]*s[j+1]*s[i+l+1];
                minm = min(minm, mm);
            }
            m[i][i+l] = minm;
        }
    }

    cout << m[0][n-1];

    return 0;
}
