#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g(5001), p(5001);
vector<vector<int>> r;
bool del[5001] = {};
int scc[5001] = {};
int iscc = 0;
int rr[5001] = {};

void dfsp(int v, bool *c, vector<int> &ts){
    c[v] = 1;
    scc[v] = iscc;
    for(int u : p[v]){
        if(!del[u] && c[u] == 0)
            dfsp(u, c, ts);
    }
    ts.push_back(v);
}

void dfsg(int v, bool *c, vector<int> &ans){
    c[v] = 1;
    for(int u : g[v]){
        if(!del[u] && c[u] == 0)
            dfsg(u, c, ans);
    }
    del[v] = true;
    ans[ans.size()-1]++;
}

void dfsr(int v, int ir, bool *c){
    rr[ir]++;
    c[v] = 1;
    for(int u : g[v]){
        if(c[u] == 0){
            if(scc[u] < scc[v])
                dfsr(u, ir+1, c);
            else
                dfsr(u, ir, c);
        }
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

    //find connected
    bool c[n] = {};
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(c[i] == 0){
            vector<int> y;
            y.push_back(i);
            c[i] = 1;
            q.push(i);
            while(!q.empty()){
                int f = q.front();
                for(int u : g[f]){
                    if(c[u] == 0){
                        y.push_back(u);
                        c[u] = 1;
                        q.push(u);
                    }
                }
                for(int u : p[f]){
                    if(c[u] == 0){
                        y.push_back(u);
                        c[u] = 1;
                        q.push(u);
                    }
                }
                q.pop();
            }
            r.push_back(y);
        }
    }

    for(int i = 0; i < r.size(); i++){
        int first = 0;
        x = r[i].size();
        iscc = 0;
        vector<int> ans;

        //find scc in each connected
        while(x != 0){
            vector<int> ts;
            bool cp[n] = {}, cg[n] = {};
            for(int u : r[i]){
                if(!del[u] && cp[u] == 0)
                    dfsp(u, cp, ts);
            }
            ans.push_back(0);
            h = ts[ts.size()-1];
            dfsg(h, cg, ans);
            x -= ans[ans.size()-1];
            iscc++;
            if(x == 0)
                first = h;
        }

        //find rank for each scc
        bool c[n] = {};
        dfsr(first, 1, c);
    }

    for(int i = 1; i <= n; i++){
        if(rr[i] == 0)
            break;
        printf("%d ", rr[i]);
    }

    return 0;
}
