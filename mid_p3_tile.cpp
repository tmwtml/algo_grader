#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int nn, mm;
int dp[11][10001][101] = {};
vector<int> a;

int findm(int n, int m, int j){
    if(m == 0 && n == 0)
        return 0;
    if(n <= 0 || m <= 0 || j > 100)
        return 1000000;
    if(dp[n][m][j] != 0)
        return dp[n][m][j];

    dp[n][m][j] = min(findm(n, m, j+1), findm(n-1, m-j*j, j)+(a[nn-n]-j)*(a[nn-n]-j));
    return dp[n][m][j];
}

int main()
{
    int x;
    scanf("%d%d", &nn, &mm);
    for(int i = 0; i < nn; i++){
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    x = findm(nn,mm,1);
    if(x >= 1000000)
        cout << -1;
    else
        cout << x;

    return 0;
}
