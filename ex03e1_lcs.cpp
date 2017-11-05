#include <iostream>
#include <stdio.h>

using namespace std;

int dp[501][501] = {};
string a, b;

//int lcs(int i, int j){
//    if(i == -1|| j == -1)
//        return 0;
//    if(dp[i][j] != 0)
//        return dp[i][j];
//    if(a[i] == b[j])
//        dp[i][j] = lcs(i-1, j-1) + 1;
//    else
//        dp[i][j] = max(lcs(i-1, j), lcs(i, j-1));
//    return dp[i][j];
//}

int main()
{
    cin >> a >> b;

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a.size()][b.size()];

    return 0;
}
