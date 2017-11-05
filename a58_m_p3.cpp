#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> hv(int n, vector<int> &v, int i){
    if(n == 1){
        return v;
    } else if(n == 2){
        vector<int> ans;
        ans.push_back(v[i] + v[i+1]);
        ans.push_back(v[i] - v[i+1]);
        return ans;
    } else {
        vector<int> ans, a, b;
        int m = n/2;
        a = hv(m, v, i);
        b = hv(m, v, i+m);
        for(int i = 0; i < m; i++){
            ans.push_back(a[i] + b[i]);
        }
        for(int i = 0; i < m; i++){
            ans.push_back(a[i] - b[i]);
        }
        return ans;
    }
}

int main()
{
    int n, x;
    scanf("%d", &n);

    vector<int> v, ans;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        v.push_back(x);
    }

    ans = hv(n, v, 0);

    for(int i = 0; i < n; i++){
        printf("%d ", ans[i]);
        //cout << ans[i] << " ";
    }
    printf("\n");

    return 0;
}
