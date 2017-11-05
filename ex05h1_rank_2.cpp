#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g(5001), p(5001);
bool del[5001] = {};
int scc[5001] = {};
int iscc = 0;
int rr[5001] = {};
int rnk[5001] = {};

void dfsp(int v, bool *c, vector<int> &ts){
    c[v] = 1;
    scc[v] = iscc;
    for(int u : p[v]){
        if(!del[u] && c[u] == 0)
            dfsp(u, c, ts);
    }
    ts.push_back(v);
}

void dfsg(int v, bool *c, int &deln){
    c[v] = 1;
    for(int u : g[v]){
        if(!del[u] && c[u] == 0)
            dfsg(u, c, deln);
    }
    del[v] = true;
    deln++;
}

void dfsr(int v, int ir){
    if(rnk[v] >= ir)
        return;
    rr[rnk[v]]--;
    rr[ir]++;
    rnk[v] = ir;
    for(int u : g[v]){
        if(scc[u] == scc[v] && rnk[u] < ir)
            dfsr(u, ir);
        else if(scc[u] < scc[v] && rnk[u] <= ir)
            dfsr(u, ir+1);
    }
}

int main()
{
    int n, m, a, b, x, h;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        p[b].push_back(a);
    }

    //find scc -> less value == bad rank
    a = n;
    while(a > 0){
        vector<int> ts;
        bool cp[n] = {}, cg[n] = {};
        for(int i = 0; i < n; i++){
            if(!del[i] && cp[i] == 0)
                dfsp(i, cp, ts);
        }
        int deln = 0;
        h = ts[ts.size()-1];
        dfsg(h, cg, deln);
        a -= deln;
        iscc++;
    }

    //find scc rank1
    vector<int> top;
    for(int i = 0; i < n; i++){
        bool t = true;
        for(int u : p[i]){
            if(scc[i] < scc[u]){
                t = false;
                break;
            }
        }
        if(t) top.push_back(i);
    }

    for(int t : top){
        dfsr(t, 1);
    }

    for(int i = 1; i <= n; i++){
        if(rr[i] == 0)
            break;
        printf("%d ", rr[i]);
    }

    return 0;
}

/*
11 9
0 1
1 2
2 4
3 4
4 5
5 6
5 7
8 9
9 10
----
3 2 2 1 1 2
*/
