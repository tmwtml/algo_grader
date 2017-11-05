#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> a;

int closet(int l, int r){
    if(l >= r)
        return 2000000000;
    if(r - l == 1)
        return (a[l].first - a[r].first)*(a[l].first - a[r].first) + (a[l].second - a[r].second)*(a[l].second - a[r].second);
    int m = (l+r)/2;
    int d = min(closet(l, m), closet(m, r)), ld = m, rd = m;
    while(ld >= l && a[ld].first >= a[m].first - d){
        ld--;
    }
    ld++;
    while(rd <= r && a[rd].first <= a[m].first + d ){
        rd++;
    }
    rd--;
    for(int i = ld; i <= m; i++){
        for(int j = m+1; j <= rd; j++){
            if(a[j].second > a[i].second+d)
                break;
            d = min(d, (a[i].first - a[j].first)*(a[i].first - a[j].first) + (a[i].second - a[j].second)*(a[i].second - a[j].second));
        }
    }
    for(int i = m; i <= rd; i++){
        for(int j = m-1; j >= ld; j--){
            if(a[j].second > a[i].second+d)
                break;
            d = min(d, (a[i].first - a[j].first)*(a[i].first - a[j].first) + (a[i].second - a[j].second)*(a[i].second - a[j].second));
        }
    }
    return d;
}

int main()
{
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        a.push_back({x,y});
    }
    sort(a.begin(), a.end());

    int d = closet(0,n-1);
    cout << d;

    return 0;
}
