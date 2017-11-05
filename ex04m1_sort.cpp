#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n;

    int c1[n] = {}, c2[n] = {}, c3[n] = {};

    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        c1[i] = c1[i-1];
        c2[i] = c2[i-1];
        c3[i] = c3[i-1];
        switch(x){
            case 1: c1[i]++;
                    break;
            case 2: c2[i]++;
                    break;
            case 3: c3[i]++;
                    break;
        }
    }

    int f = n - (c1[c1[n]] + c2[c1[n]+c2[n]]-c2[c1[n]] + c3[n]-c3[c1[n]+c2[n]]);
    int p3 = abs(c2[c1[n]] - (c1[c1[n]+c2[n]]-c1[c1[n]]));
    int p2 = (f - 3*p3)/2;

    printf("%d", 2*p3 + p2);

    return 0;
}
