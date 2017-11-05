#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int mcs(vector<int> a, int i, int j){
    if(i >= j){
        return(a[i]);
    } else {
        int mid = (i+j)/2;
        int x = mcs(a, i, mid);
        int y = mcs(a, mid+1, j);
        int z1 = a[mid];
        int z2 = a[mid];
        int s = 0;
        for(int k = mid; k <= j; k++){
            s += a[k];
            if(s > z2)
                z2 = s;
        }
        s = 0;
        for(int k = mid; k >= i; k--){
            s += a[k];
            if(s > z1)
                z1 = s;
        }
        int z = z1+z2-a[mid];
        return max(z,max(x,y));
    }
}

int main()
{
    int n, x;
    scanf("%d", &n);

    vector<int> a;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a.push_back(x);
    }

    cout << mcs(a, 0, n-1) << endl;

    return 0;
}
