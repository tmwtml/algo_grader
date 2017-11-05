#include <iostream>
#include <stdio.h>

using namespace std;

int n, k, x;
int p[10001] = {};
int s[10001] = {};

int mink(int l){
    int ml = max(l-k-1, 0);
    int mp = s[ml]+p[l];
    int m = l;
    for(int i = 1; i <= k; i++){
        ml = max(l-i-k-1, 0);
        int pi = max(l-i, 1);
        if(s[ml]+p[pi] < mp){
            mp = s[ml]+p[pi];
            m = l-i;
        }
    }
    return m;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        p[i] = x;
    }

    int m = mink(min(k+1, n)), ml;
    for(int i = 1; i <= k+1; i++){
        s[i] = p[m];
    }
    for(int i = k+2; i <= n; i++){
        m = mink(i);
        ml = max(m-k-1, 0);
        s[i] = s[ml]+p[m];
        if(m == i){
            for(int j = 1; j <= k; j++){
                s[i-j] = min(s[i], s[i-j]);
            }
        }
    }

    cout << s[n];

    return 0;
}
