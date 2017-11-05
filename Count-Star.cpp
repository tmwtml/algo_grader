#include <iostream>
#include <stdio.h>

using namespace std;

long long int t[61] = {};
long long int s[61] = {};

int main()
{
    int q, m;
    long long int x, a, b;
    t[0] = 1;
    s[0] = 1;
    for(int i = 1; i < 61; i++){
        t[i] = (2*t[i-1])%1000000000000000007;
        s[i] = (3*s[i-1])%1000000000000000007;
    }
    cin >> q;
    for(int j = 0; j < q; j++){
        m = 1, a = 1, b = 0;
        scanf("%lld", &x);

        long long int y = x;

        for(int i = 60; i >= 0; i--){
            if(t[i] <= x){
                b = (b+(m*s[i])%1000000000000000007)%1000000000000000007;
                m *= 2;
                x -= t[i];
            }
        }

        for(int i = 60; i >= 0; i--){
            if(t[i] < y){
                y -= t[i];
                a = (a*2)%1000000000000000007;
            }
        }
        printf("%lld %lld\n", a, b);
    }

    return 0;
}
