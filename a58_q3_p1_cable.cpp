#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int p[1005] = {};
int h[1005] = {};

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

    int g[n][n] = {};
    vector<pair<int,pair<int,int>>> w;
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j <= n-i-1; j++){
            scanf("%d", &g[i][i+j]);
            g[i+j][i] = g[i][i+j];
            w.push_back({g[i][i+j],{i,i+j}});
        }
    }

    for(int i = 0; i < n; i++){
        p[i] = i;
        h[i] = 1;
    }

    int mst = 0;
    sort(w.begin(), w.end());
    for(int i = 0; i < w.size(); i++){
        int u = w[i].second.first;
        int v = w[i].second.second;
        int ru = root(u);
        int rv = root(v);
        if(ru != rv){
            mst += g[u][v];
            cout << u << " " << v << " " << g[u][v] << endl;
            if(h[ru] < h[rv]){
                p[ru] = rv;
            } else if(h[ru] > h[rv]){
                p[rv] = ru;
            } else {
                p[ru] = rv;
                h[rv]++;
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
