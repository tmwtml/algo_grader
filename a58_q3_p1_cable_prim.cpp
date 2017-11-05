#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int g[1005][1005] = {};
int p[1005], d[1005];
bool inMst[1005];

int root(int u){
    while(p[u] != u){
        u = p[u];
    }
    return u;
}

int main()
{
    int n, x;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        for(int j = 1; j <= n-i-1; j++){
            scanf("%d", &g[i][i+j]);
            g[i+j][i] = g[i][i+j];
        }
    }

    for(int i = 0; i < n; i++){
        d[i] = 5000;
    }
    p[0] = 0;
    d[0] = 0;
    int mst = 0;
    for(int i = 0; i < n; i++){
        int v = 0;
        for(int j = 0; j < n; j++){
            if(!inMst[j] && d[j] < d[v])
                v = j;
        }
        inMst[v] = true;
        cout << v << " " << p[v] << " " << d[v] << endl;
        mst += d[v];
        d[v] = 5000;
        for(int j = 0; j <= n; j++){
            if(!inMst[j] && g[j][v] > 0 && g[j][v] < d[j]){
                d[j] = g[j][v];
                p[j] = v;
            }
        }
    }
    cout << mst;

    return 0;
}

/*
4
1 3 4
2 7
6

5
4 3 6 7
4 2 5
6 5
7
*/
