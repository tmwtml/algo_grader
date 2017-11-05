#include <iostream>
#include <stdio.h>

using namespace std;

int a[1000][1000] = {};
int p[1000][1000] = {};

int pp(int i, int j){
    if(i < 0 || j < 0)
        return 0;
    return p[i][j];
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
            p[i][j] = pp(i-1,j) + pp(i,j-1) - pp(i-1,j-1) + a[i][j];
        }
    }

    int r1, c1, r2, c2;
    for(int i = 0; i < k; i++){
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("%d\n", pp(r2,c2) - pp(r1-1,c2) - pp(r2,c1-1) + pp(r1-1,c1-1));
    }

    return 0;
}
