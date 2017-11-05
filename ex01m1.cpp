#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void fil(vector<pair<int,pair<int,int>>> &f, int p, int a, int b){
    f.push_back(make_pair(p, make_pair(a, b)));
}

vector<pair<int,pair<int,int>>> fillFour(int x, int y, int a, int b) {
    vector<pair<int,pair<int,int>>> f;
    if ((x%4 == 1 || x%4 == 2) && (y%4 == 1 || y%4 == 2)){
        fil(f, (x%4-1)+2*(y%4-1), a+1, b+1);
        fil(f, 3, a, b);
        fil(f, 2, a+2, b);
        fil(f, 1, a, b+2);
        fil(f, 0, a+2, b+2);
    } else if((x%4 == 0 || x%4 == 1) && (y%4 == 0 || y%4 == 1)){
        fil(f, 0, a+1, b+1);
        fil(f, (x%4)+2*(y%4), a, b);
        fil(f, 2, a+2, b);
        fil(f, 1, a, b+2);
        fil(f, 0, a+2, b+2);
    } else if((x%4 == 2 || x%4 == 3) && (y%4 == 0 || y%4 == 1)){
        fil(f, 1, a+1, b+1);
        fil(f, 3, a, b);
        fil(f, (x%4-2)+2*(y%4), a+2, b);
        fil(f, 1, a, b+2);
        fil(f, 0, a+2, b+2);
    } else if((x%4 == 0 || x%4 == 1) && (y%4 == 2 || y%4 == 3)){
        fil(f, 2, a+1, b+1);
        fil(f, 3, a, b);
        fil(f, 2, a+2, b);
        fil(f, (x%4)+2*(y%4-2), a, b+2);
        fil(f, 0, a+2, b+2);
    } else if((x%4 == 2 || x%4 == 3) && (y%4 == 2 || y%4 == 3)){
        fil(f, 3, a+1, b+1);
        fil(f, 3, a, b);
        fil(f, 2, a+2, b);
        fil(f, 1, a, b+2);
        fil(f, (x%4-2)+2*(y%4-2), a+2, b+2);
    }
    return f;
}

vector<pair<int,pair<int,int>>> fillAll(int l, int x, int y, int a, int b) {
    vector<pair<int,pair<int,int>>> f, ff, f1, f2, f3, f4;
    if(l == 2){
        fil(f, (x%4)+2*(y%4), a, b);
    } else if (l == 4){
        ff = fillFour(x, y, a, b);
        f.insert(f.end(), ff.begin(), ff.end());
    } else {
        int nl = l/2;
        f1 = fillAll(nl, a+nl-1, b+nl-1, a, b);
        f2 = fillAll(nl, a+nl, b+nl-1, a+nl, b);
        f3 = fillAll(nl, a+nl-1, b+nl, a, b+nl);
        f4 = fillAll(nl, a+nl, b+nl, a+nl, b+nl);
        if(x < a+nl && y < b+nl){
            fil(f, 0, a+nl-1, b+nl-1);
            f1 = fillAll(nl, x, y, a, b);
        } else if(x >= a+nl && y < b+nl){
            fil(f, 1, a+nl-1, b+nl-1);
            f2 = fillAll(nl, x, y, a+nl, b);
        } else if(x < a+nl && y >= b+nl){
            fil(f, 2, a+nl-1, b+nl-1);
            f3 = fillAll(nl, x, y, a, b+nl);
        } else if(x >= a+nl && y >= b+nl){
            fil(f, 3, a+nl-1, b+nl-1);
            f4 = fillAll(nl, x, y, a+nl, b+nl);
        }
        f.insert(f.end(), f1.begin(), f1.end());
        f.insert(f.end(), f2.begin(), f2.end());
        f.insert(f.end(), f3.begin(), f3.end());
        f.insert(f.end(), f4.begin(), f4.end());
    }
    return f;
}

int main()
{
    int l, x, y;
    cin >> l >> x >> y;

    vector<pair<int,pair<int,int>>> f = fillAll(l, x, y, 0, 0);

    printf("%d\n", f.size());
    for(auto i : f){
        printf("%d %d %d\n", i.first, i.second.first, i.second.second);
    }

    return 0;
}
