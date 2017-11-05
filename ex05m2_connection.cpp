#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, e, k, a, b;
    cin >> n >> e >> k;

    vector<vector<set<int>>> g(5, vector<set<int>> (n));

    for(int i = 0; i < n; i++){
        g[1][i].insert(i);
    }

    for(int i = 0; i < e; i++){
        scanf("%d%d", &a, &b);
        g[1][a].insert(b);
        g[1][b].insert(a);
    }

    for(int f = 2; f <= 4; f++){
        for(int i = 0; i < n; i++){
            for(int v : g[f-1][i]){
                g[f][i].insert(v);
                for(int u : g[1][v])
                    g[f][i].insert(u);
            }
        }
    }

    for(int k = 1; k <= 4; k++){
        cout << "k = " << k << " : ";
        for(int i = 0; i < n; i++){
            cout << g[k][i].size() << " ";
        }
        cout << endl;
    }

    int maxf = 0;
    for(int i = 0; i < n; i++){
        maxf = max(maxf, (int)(g[k][i].size()));
    }
    cout << maxf;


    return 0;
}
