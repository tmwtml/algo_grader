#include <iostream>
#include <vector>

using namespace std;

int game(long long int n, long long int a, long long int b, long long int l, long long int r){
    long long int m = (a+b)/2;
    if(l > r)
        return 0;
    if(n == 0 || n == 1)
        return n;
    if(l <= m && r >= m)
        return game(n/2, a, m-1, l, m-1) + n%2 + game(n/2, m+1, b, m+1, r);
    if(r < m)
        return game(n/2, a, m-1, l, r);
    if(l > m){
        return game(n/2, m+1, b, l, r);
    }
}

int main()
{
    long long int n, i, l, r, x;
    cin >> n >> l >> r;

    i = 1;
    x = n;
    while(x > 1){
        i = 2*i+1;
        x /= 2;
    }

    cout << game(n,1,i,l,r) << endl;

    return 0;
}
