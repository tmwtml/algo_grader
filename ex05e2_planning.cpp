#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g(1001);
vector<int> ts;
int c[1001] = {};

void dfs(int v){
    c[v] = 1;
    for(int u : g[v]){
        if(c[u] == 0)
            dfs(u);
    }
    ts.push_back(v);
}

int main()
{
    int n, m, x, f;
    cin >> n;

    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &x);
            g[x].push_back(i);
        }
    }

    for(int i = 0; i < n; i++){
        if(c[i] == 0)
            dfs(i);
    }

    for(int i = ts.size()-1; i >= 0; i--){
        printf("%d ", ts[i]);
    }

    return 0;
}
