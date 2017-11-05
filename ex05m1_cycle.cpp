#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int t, n, e, a, b;

bool dfs(int v, vector<vector<int>> &g, int *c, int *p){
    c[v] = 1;
    for(int u : g[v]){
        if(u == p[v])
            continue;
        if(c[u] == 0){
            p[u] = v;
            if(dfs(u, g, c, p))
                return true;
        } else if(c[u] == 1){
            return true;
        }
    }
    c[v] = 2;
    return false;
}

bool hasCycle(){
    scanf("%d%d", &n, &e);
    vector<vector<int>> g(n);

    for(int i = 0; i < e; i++){
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int c[n] = {}, p[n];
    for(int v = 0; v < n; v++){
        if(c[v] == 0 && dfs(v, g, c, p))
            return true;
    }
    return false;
}

int main()
{
    cin >> t;
    for(int j = 0; j < t; j++){
        if(hasCycle())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
