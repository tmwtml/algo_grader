#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    string x, y;
    cin >> n >> m;
    cin >> x >> y;

    int l[n+1][m+1];
    string ans = "";

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            scanf("%d", &l[i][j]);
        }
    }

    int a = n, b = m;
    while(a > 0 && b > 0){
        while(l[a][b] == l[a-1][b]){
            a--;
        }
        a++;
        while(l[a][b] == l[a][b-1]){
            b--;
        }
        b++;
        ans = x[a-1] + ans;
        a--;
        b--;
    }

    cout << ans;

    return 0;
}
