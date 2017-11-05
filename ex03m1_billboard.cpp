#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, x;
    scanf("%d", &n);

    int s[n+1] = {};
    int t[n+1] = {};
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        s[i] = x;
    }

    t[1] = s[1];
    for(int i = 2; i <= n; i++){
        t[i] = max(t[i-2] + s[i], t[i-1]);
    }

    cout << t[n];

    return 0;
}
