#include <iostream>
#include <stdio.h>

using namespace std;

char g(int n){
    int k = 0;
    int l = 3;
    char ans;
    while(l < n){
        k++;
        l = 2*l + k+3;
    }

    l = (l - k-3)/2;
    if(n == l+1){
        return 'g';
    } else if (n <= l+k+3){
        return 'a';
    } else if (n == l+k+4){
        return 'g';
    } else {
        return g(n-l-k-3);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << g(n);

    return 0;
}
