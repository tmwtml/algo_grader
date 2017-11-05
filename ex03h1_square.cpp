#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int r, c, k = 0, ans = 0;
    scanf("%d%d", &r, &c);

    int dp[r+1][c+1] = {};
    char x[c];

    for(int i = 1; i <= r; i++){
        scanf("%s", &x);
        k = 0;
        for(int j = 1; j <= c; j++){
            if(x[j-1] == '1')
                k++;
            else
                k = 0;
            dp[i][j] = k;
            if(k > ans){
                int m = k;
                for(int l = 1; l < m && i-l >= 0; l++){
                    if(dp[i-l][j] < m){
                        m = dp[i-l][j];
                    }
                }
                ans = max(ans, m);
            }
        }
    }

    cout << ans;

    return 0;
}
