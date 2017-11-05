#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n, m, x;
    scanf("%d %d", &n, &m);

    vector<int>a (n+1);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a[i] = x;
    }

    a[n] = -1;

    for(int i = 0; i < m; i++){
        scanf("%d", &x);

        int l = 0;
        int r = n;
        int c = n/2;

        while(true){
            if(a[c] == x){
                break;
            } else if(a[c] < x){
                if(c >= n-1){
                    c = n-1;
                    break;
                } else if(a[c+1] > x){
                    break;
                }
                l = c;
            } else {
                if(c <= 0){
                    c = n;
                    break;
                } else if(a[c-1] < x){
                    c -= 1;
                    break;
                }
                r = c;
            }
            c = (l+r)/2;
        }

        printf("%d\n", a[c]);
    }

    return 0;
}
