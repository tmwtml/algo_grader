#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int mm[10001][21] = {};
int cc[21] = {};

int coin(int m, int c){
    if(mm[m][c] > 0)
        return mm[m][c];
    if(c == 1)
        mm[m][c] = m/c;
    else if(m - cc[c] < 0)
        mm[m][c] = coin(m, c-1);
    else
        mm[m][c] = min(coin(m - cc[c], c)+1, coin(m, c-1));
    return mm[m][c];
}

int main()
{
    int n, m, x;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        cc[n-i] = x;
    }

    cout << coin(m, n);

    return 0;
}
