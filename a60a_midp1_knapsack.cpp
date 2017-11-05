#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n, m, x;
    vector<int> ans;
    cin >> n >> m;

    int v[n+1];
    int w[m+1];
    int p[n+1][m+1];

    for(int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }

    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++){
            if (i == 0 || j == 0) p[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= w[i]) {
                if (p[i-1][j] >= p[i-1][j-w[i]]+v[i]) {
                    p[i][j] = p[i-1][j];
                } else {
                    p[i][j] = p[i-1][j-w[i]]+v[i];
                }
            } else p[i][j] = p[i-1][j];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            scanf("%d", &x);
            if(x != p[i][j]){
                x = v[-1];
            }
        }
    }

    int a = n, b = m;
    int nn = 0;
    while(a > 0 && b > 0){
        if(b >= w[a] && p[a-1][b-w[a]]+v[a] >= p[a-1][b]){
        //if(p[a][b] != p[a-1][b]){
            nn++;
            ans.push_back(a);
            b -= w[a];
        }
        a--;
    }

    printf("%d\n", nn);
    for(int i = ans.size()-1; i >= 0; i--)
        printf("%d ", ans[i]);

    return 0;
}
