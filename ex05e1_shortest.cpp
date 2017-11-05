#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int r, c, f, d, x, y;
    char s;
    scanf("%d%d", &r, &c);

    int map[r+1][c+1] = {};

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf("\r%c", &s);
            if(s == '#')
                map[i][j] = 100;
            else
                map[i][j] = -1;
        }
    }

    queue<pair<int,int>> q;
    q.push({1,1});
    map[1][1] = 0;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        d = map[x][y];
        if(x > 1 && map[x-1][y] == -1){
            q.push({x-1, y});
            map[x-1][y] = d+1;
        }
        if(x < r && map[x+1][y] == -1){
            q.push({x+1, y});
            map[x+1][y] = d+1;
        }
        if(y > 1 && map[x][y-1] == -1){
            q.push({x, y-1});
            map[x][y-1] = d+1;
        }
        if(y < c && map[x][y+1] == -1){
            q.push({x, y+1});
            map[x][y+1] = d+1;
        }
        q.pop();
    }

    cout << map[r][c];


    return 0;
}
