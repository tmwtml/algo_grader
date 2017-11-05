#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int ans;
int d = 0;
int path[100001];
int c[100001];
vector<vector<int>> g(100001);

void dfs(int v, int p){
    c[v] = 1;
    d++;
    path[v] = d;
    for(int u : g[v]){
        if(c[u] == 0)
            dfs(u, v);
        else if(c[u] == 1 && u != p){
            ans = path[v]-path[u]+1;
        }
    }
    c[v] = 2;
    d--;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,0);
    cout << ans;

    return 0;
}
