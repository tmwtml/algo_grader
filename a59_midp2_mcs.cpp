#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, x, m, mcs;
    cin >> n;

    scanf("%d", &x);
    m = x;
    mcs = m;
    for(int i = 1; i < n; i++){
        scanf("%d", &x);
        m = max(x, x+m);
        mcs = max(mcs, m);
    }

    cout << mcs;

    return 0;
}
