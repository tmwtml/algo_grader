#include <iostream>
#include <stdio.h>

using namespace std;

int s[1001] = {};
int lto[1001] = {};
int lmax[1001] = {};
int smax[1001] = {};

int main()
{
    int n, x;
    cin >> n;

    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        s[i] = x;
    }

    lmax[1] = 1;
    lto[1] = 1;
    smax[1] = s[1];

    for(int d = 2; d <= n; d++){
        if(s[d] > smax[d-1]){
            lmax[d] = lmax[d-1] + 1;
            lto[d] = lmax[d];
            smax[d] = s[d];
        } else {
            int t = d-1;
            lto[d] = 1;
            while(t > 0){
                if(s[t] < s[d])
                    lto[d] = max(lto[d], lto[t] + 1);
                t--;
            }
            if(lto[d] >= lmax[d-1]){
                lmax[d] = lto[d];
                smax[d] = s[d];
            } else {
                lmax[d] = lmax[d-1];
                smax[d] = smax[d-1];
            }
        }
    }

    cout << lmax[n];

    return 0;
}
