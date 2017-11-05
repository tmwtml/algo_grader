#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int n, m, k, d, e, l;
    scanf("%d %d %d", &n, &m, &k);

    int a[k+1];
    queue<int> q;

    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &d, &e, &l);
        if(e == 0)
            a[d] = l;
        else
            a[d] = -l;
    }

    for(int i = 1; i <= k; i++){
        int f = q.front();
        if(!q.empty() && a[i] > 0 && f < 0){
            printf("%d\n", -q.front());
            q.pop();
        } else if(!q.empty() && a[i] < 0 && f > 0){
            printf("%d\n", q.front());
            q.pop();
        } else {
            printf("0\n");
            q.push(a[i]);
        }
    }

    return 0;
}
