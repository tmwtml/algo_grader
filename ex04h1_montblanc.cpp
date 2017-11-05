#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int camp[n+1] = {};
    int dif = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &camp[i]);
        dif = max(camp[i]-camp[i-1], dif);
    }

    int d = 100001;
    int k = max(camp[n-1]/m, dif)-1;
    int h;
    while(d > m){
        k++;
        d = 1;
        h = 0;
        for(int i = 1; i < n; i++){
            if(camp[i+1] > h + k){
                h = camp[i];
                d++;
            }
        }
    }

    cout << k << " " << d;

    return 0;
}
