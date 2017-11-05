#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
int path[1001] = {};
int c[1001] = {};
int mc[1001][1001] = {};

int cost(int x, int y){
    if(mc[x][y] != 0)
        return mc[x][y];
    int a = min(x, y);
    int b = max(x, y);
    mc[x][y] = min(c[b]-c[a], c[m]-(c[b]-c[a]));
    mc[y][x] = mc[x][y];
    return mc[x][y];
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        scanf("%d", &path[i]);
    }

    for(int i = 1; i <= m; i++){
        scanf("%d", &c[i]);
        c[i] = c[i] + c[i-1];
    }

    int a, b, c1, c2, c3, p1, p2, s;
    for(int t = 0; t < n; t++){
        scanf("%d%d", &a, &b);
        s = 0;
        for(int i = 0; i < m; i++){
            p1 = path[i%m];
            p2 = path[(i+1)%m];
            c1 = cost(p1, p2);                  //p1 -> p2
            c2 = cost(p1, a) + cost(b, p2);     //p1 -> a -> b -> p2
            c3 = cost(p1, b) + cost(a, p2);     //p1 -> b -> a -> p2
            s += min(min(c1,c2),c3);
        }
        printf("%d\n", s);
    }

    return 0;
}
