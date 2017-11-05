#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g(1001), p(1001);
vector<int> ans;
bool del[1001] = {};

void dfsp(int v, int *c, vector<int> &ts){
    c[v] = 1;
    for(int u : p[v]){
        if(!del[u] && c[u] == 0)
            dfsp(u, c, ts);
    }
    ts.push_back(v);
}

void dfsg(int v, int *c){
    c[v] = 1;
    for(int u : g[v]){
        if(!del[u] && c[u] == 0)
            dfsg(u, c);
    }
    del[v] = true;
    ans[ans.size()-1]++;
}

int main()
{
    int n, m, x, a, h;
    cin >> n;

    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &x);
            g[i].push_back(x);
            p[x].push_back(i);
        }
    }

    a = n;
    while(a > 0){
        vector<int> ts;
        int cp[n] = {}, cg[n] = {};
        for(int i = 0; i < n; i++){
            if(!del[i] && cp[i] == 0)
                dfsp(i, cp, ts);
        }
        ans.push_back(0);
        h = ts[ts.size()-1];
        dfsg(h, cg);
        a -= ans[ans.size()-1];
    }

    sort(ans.begin(), ans.end());

    for(int x : ans)
        printf("%d ", x);

    return 0;
}
