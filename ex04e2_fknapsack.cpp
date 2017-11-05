#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double m;
    int n;
    cin >> m >> n;

    double v[n], w[n];
    vector<pair<double,int>> frac(n);  //{w/v, {v, w}}

    for(int i = 0; i < n; i++){
        scanf("%lf", &v[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &w[i]);
        frac[i].first = w[i]/v[i];
        frac[i].second = i;
    }

    sort(frac.begin(), frac.end());

    double p = 0, c = 0;
    int i = 0;
    while(c < m && i < n){
        if(c + w[frac[i].second] <= m){
            p += v[frac[i].second];
            c += w[frac[i].second];
        } else {
            p += v[frac[i].second]*(m-c)/w[frac[i].second];
            c = m;
        }
        i++;
    }

    printf("%.4f", p);

    return 0;
}
