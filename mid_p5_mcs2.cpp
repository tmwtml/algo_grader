#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> a;

pair<int,int> mcs(int i, int j){
    if(i >= j){
        return {a[i], a[i]};
    } else {
        int mid = (i+j)/2;
        pair<int,int> x = mcs(i, mid);
        pair<int,int> y = mcs(mid+1, j);

        int zmax1 = a[mid];
        int zmax2 = a[mid];
        int zmin1 = a[mid];
        int zmin2 = a[mid];
        int s = 0;
        for(int k = mid; k <= j; k++){
            s += a[k];
            if(s > zmax2)
                zmax2 = s;
            if(s < zmin2)
                zmin2 = s;
        }
        s = 0;
        for(int k = mid; k >= i; k--){
            s += a[k];
            if(s > zmax1)
                zmax1 = s;
            if(s < zmin1)
                zmin1 = s;
        }
        int zmax = zmax1+zmax2-a[mid];
        int zmin = zmin1+zmin2-a[mid];
        return {max(zmax,max(x.first,y.first)), min(zmin,min(x.second,y.second))};
    }
}

int main()
{
    int n, x;
    scanf("%d", &n);

    int suma = 0;
    int maxx = -1001;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a.push_back(x);
        suma += x;
        if(x > maxx)
            maxx = x;
    }

    if(maxx < 0)
        cout << maxx << endl;
    else
        cout << max(mcs(0, n-1).first, suma - mcs(0, n-1).second) << endl;

    return 0;
}
