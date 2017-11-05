#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m, x;
    scanf("%d%d", &n, &m);

    int c[n+1] = {};

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        c[i] = x;
    }

    for(int i = 0; i < m; i++){
        int l = 0;
        int r = n+1;
        int m = (l+r)/2;
        scanf("%d", &x);
        while(m > 0 && m < n && !(x < c[m] && x >= c[m-1])){
            if(x < c[m]){
                r = m;
            } else {
                l = m;
            }
            m = (l+r)/2;
        }
        printf("%d\n", m-1);
    }

    return 0;
}
