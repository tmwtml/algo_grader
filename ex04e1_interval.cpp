#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> time(n);      //{end, start}

    for(int i = 0; i< n; i++){
        scanf("%d", &time[i].second);
    }
    for(int i = 0; i< n; i++){
        scanf("%d", &time[i].first);
    }
    sort(time.begin(), time.end());

    int ans = 1;
    int lc = 0;
    for(int i = 1; i < n; i++){
        if(time[i].second >= time[lc].first){    //i start after lc end
            lc = i;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
