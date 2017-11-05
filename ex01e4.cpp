#include <iostream>
#include <stdio.h>

using namespace std;

int modexpo(int x, int n, int k){
    x = x%k;
    if(n == 0)
        return 1;
    if(n == 1)
        return x;

    int i = 1;
    int a = x;
    while(a < k){
        if(n == i){
            return a;
        }
        a *= x;
        i++;
    }
    a = a%k;

    return (modexpo(a, n/i, k) * modexpo(x, n%i, k))%k;
}

int main()
{
    int x, n, k;
    cin >> x >> n >> k;

    cout << modexpo(x, n, k);

    return 0;
}
