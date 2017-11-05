#include <iostream>
#include <stdio.h>

using namespace std;

int y[1000001] = {0};

int sds(int x){
    if(x == 1)
        return 1;
    if (x <= y[y[0]]){
        int i = 0;
        int j = y[0];
        while(true){
            int m = (i+j)/2;
            if(x <= y[m] && x > y[m-1])
                return m;
            if(x > y[m])
                i = m+1;
            else
                j = m-1;
        }
    }
    while(x > y[y[0]]){
        int j = sds(y[0])+1;
        int k = sds(j);
        for(int m = 1; m <= k; m++){
            y[y[0] + m] = y[y[0]] + j*m;
        }
        y[0] += k;
    }
    return sds(x);
}

int main()
{
    int n, x;
    scanf("%d", &n);

    y[1] = 1;
    y[2] = 3;
    y[3] = 5;
    y[0] = 3;

    while(n--){
        scanf("%d", &x);
        printf("%d\n", sds(x));
    }

//    for(int i = 1; i < n; i++){
//        printf("%d\n", sds(i));
//    }

    return 0;
}
