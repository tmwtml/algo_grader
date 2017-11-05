#include <iostream>
#include <stdio.h>

using namespace std;

int t[101][101] =  {};
int s[101][101] =  {};

int main()
{
    int n, x;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &x);
            t[i][j] = x;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            s[i][j] = t[i][j] + max(s[i-1][j-1], s[i-1][j]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, s[n][i]);
    }
    cout << ans;

    return 0;
}
