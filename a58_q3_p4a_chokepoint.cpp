#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int ce[100001];
bool cv[100001] = {};
long long int f[100001] = {};
int set_e[100001];
vector<pair<int,int>> e(100001);
vector<vector<int>> g(100001);  //edge of v

int find_friend(int i){
    if(f[i] != 0)
        return f[i];
    //cout << "find " << i << endl;
    ce[i] = 1;
    int a = e[i].first;
    if(cv[a] > 0){
        //cout << "pass " << a << endl;
        a = e[i].second;
    }
    //cout << "a = " << a << endl;
    cv[a] = 1;
    f[i] = 1;
    set_e[i] = a;
    for(int l : g[a]){
        //cout << i << " " << a << " " << l << endl;
        if(l != i){
            //cout << "yes" << endl;
            f[i] += find_friend(l);
        }
    }
    ce[i] = 2;
    return f[i];
}

int main()
{
    long long int n, a, b;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        g[a].push_back(i);
        g[b].push_back(i);
        e[i] = {a,b};
    }

    for(int i = 0; i < n-1; i++){
        if(f[i] == 0){
            find_friend(i);
        }
    }

    for(int i = 0; i < n; i++){
        long long int ans = n*(n-1);
        for(int l : g[i]){
            if(set_e[l] != i){
                ans -= f[l]*(f[l]-1);
            } else {
                ans -= (n-f[l])*(n-f[l]-1);
            }
        }
        printf("%lld\n", ans/2);
    }
//    cout << "f : ";
//    for(int i = 0; i < n-1; i++){
//        cout << f[i] << " ";
//    }
//    cout << endl;
//
//    for(int i = 0; i < n-1; i++){
//        cout << "set" << i << " : ";
//        for(int x : set_e[i]){
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//
//    for(int i = 0; i < n; i++){
//        int ans = n*(n-1);
//        cout << ans/2 << " ";
//        for(int l : g[i]){
//            cout << "l=" << l << " ";
//            if(set_e[l].find(i) == set_e[l].end()){
//                ans -= f[l]*(f[l]-1);
//                cout << ans/2 << " ";
//            } else {
//                ans -= (n-f[l])*(n-f[l]-1);
//                cout << ans/2 << " ";
//            }
//        }
//        cout << ans/2 << endl;
//    }

    return 0;
}

/*
6
1 3
1 2
1 5
4 5
0 3
---
5
13
5
9
5
9
*/
