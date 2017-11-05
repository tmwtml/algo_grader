#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

vector<int> c(1000);
int n, a;

long long int time(long long int x, long long int t1, long long int t2){
    if(x <= n)
        return 0;
    long long int m = 0;
    int s = 0;
    long long int tm = (t1+t2)/2;
    for(int i = 0; i < n; i++){
        m += ceil(tm/double(c[i]));
        if(tm%c[i] == 0)
            s++;
    }

    if(s > 0 && x > m && x <= m+s)
        return tm;
    if(m >= x)
        return time(x, t1, tm);
    if(m < x)
        return time(x, tm, t2);

}

int main()
{
    int j;
    long long int x;
    scanf("%d %d", &n, &a);

    for(int i = 0; i < n; i++){
        scanf("%d", &j);
        c[i] = j;
    }

    while(a--){
        scanf("%lld", &x);
        printf("%lld\n", time(x, 0, c[0]*x));
    }

    return 0;
}
