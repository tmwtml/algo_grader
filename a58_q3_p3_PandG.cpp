#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> grid(111, vector<int>(111));
vector<vector<int>> path(111, vector<int>(111));
int R, C;

void bfsg(int T, int ti, int r, int c){
    if(grid[r][c] >= 0 && grid[r][c] < ti)
        return;
    queue<pair<int,int>> q;
    q.push({r,c});
    grid[r][c] = ti;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        int t = grid[x][y]+1;
        if(t > T){
            q.pop();
            continue;
        }
        if(!(x-1 < 0 || x-1 >= R || y < 0 || y >= C) && grid[x-1][y] < 1000 && (grid[x-1][y] == -1 || t < grid[x-1][y])){
            grid[x-1][y] = t;
            q.push({x-1,y});
        }
        if(!(x+1 < 0 || x+1 >= R || y < 0 || y >= C) && grid[x+1][y] < 1000 && (grid[x+1][y] == -1 || t < grid[x+1][y])){
            grid[x+1][y] = t;
            q.push({x+1,y});
        }
        if(!(x < 0 || x >= R || y-1 < 0 || y-1 >= C) && grid[x][y-1] < 1000 && (grid[x][y-1] == -1 || t < grid[x][y-1])){
            grid[x][y-1] = t;
            q.push({x,y-1});
        }
        if(!(x < 0 || x >= R || y+1 < 0 || y+1 >= C) && grid[x][y+1] < 1000 && (grid[x][y+1] == -1 || t < grid[x][y+1])){
            grid[x][y+1] = t;
            q.push({x,y+1});
        }
        q.pop();
    }
}

bool bfsp(int T, int r, int c){
    if(grid[r][c] == 0)
        return false;
    if(grid[r][c] == -1)
        return true;
    queue<pair<int,int>> q;
    queue<int> qt;
    q.push({r,c});
    path[r][c] = 0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        int ti = path[x][y]+1;
        if(ti > T){
            q.pop();
            continue;
        }
        if(!(x < 0 || x >= R || y < 0 || y > C) && path[x][y] == -1 && (grid[x][y] == -1 || ti < grid[x][y])){
            if(grid[x][y] == -1)
                return true;
            path[x][y] = ti;
            q.push({x,y});
        }
        if(!(x-1 < 0 || x-1 >= R || y < 0 || y > C) && path[x-1][y] == -1 && (grid[x-1][y] == -1 || ti < grid[x-1][y])){
            if(grid[x-1][y] == -1)
                return true;
            path[x-1][y] = ti;
            q.push({x-1,y});
        }
        if(!(x+1 < 0 || x+1 >= R || y < 0 || y > C) && path[x+1][y] == -1 && (grid[x+1][y] == -1 || ti < grid[x+1][y])){
            if(grid[x+1][y] == -1)
                return true;
            path[x+1][y] = ti;
            q.push({x+1,y});
        }
        if(!(x < 0 || x >= R || y-1 < 0 || y-1 > C) && path[x][y-1] == -1 && (grid[x][y-1] == -1 || ti < grid[x][y-1])){
            if(grid[x][y-1] == -1)
                return true;
            path[x][y-1] = ti;
            q.push({x,y-1});
        }
        if(!(x < 0 || x >= R || y+1 < 0 || y+1 > C) && path[x][y+1] == -1 && (grid[x][y+1] == -1 || ti < grid[x][y+1])){
            if(grid[x][y+1] == -1)
                return true;
            path[x][y+1] = ti;
            q.push({x,y+1});
        }
        q.pop();
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    while(k--){
        int n,T,r,c,gf,gsf,gss;
        cin >> R >> C >> n >> T >> r >> c;
        vector<pair<int,pair<int,int>>> ghost(n);
        for(int y = 0; y < n; y++){
            cin >> gf >> gsf >> gss;
            ghost[y].first = gf;
            ghost[y].second.first = gsf;
            ghost[y].second.second = gss;
        }
        for(int i = 0; i < R; i++){
            string s;
            cin >> s;
            for(int j = 0; j < C; j++){
                if(s[j] == '.'){
                    grid[i][j] = {-1};
                    path[i][j] = {-1};
                } else {
                    grid[i][j] = {1000};
                    path[i][j] = {1000};
                }
            }
        }
        for(auto g : ghost){
            bfsg(T, g.first, g.second.first, g.second.second);
        }

        if(bfsp(T, r, c))
            printf("YES\n");
        else
            printf("NO\n");

//        for(int i = 0; i < R; i++){
//            for(int j = 0; j < C; j++){
//                cout << grid[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for(int i = 0; i < R; i++){
//            for(int j = 0; j < C; j++){
//                cout << path[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }

    return 0;
}

