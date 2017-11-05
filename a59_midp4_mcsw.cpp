#include <iostream>
#include <stdio.h>

using namespace std;

int n, w;
int a[200001];
int maxc[200001];
int sumc[200001];
int s[200001];

int main()
{
    cin >> n >> w;

    scanf("%d", &a[0]);
    maxc[0] = a[0];
    sumc[0] = a[0];
    s[0] = 0;
    for(int i = 1; i < n; i++){
        scanf("%d", &a[i]);
        sumc[i] = sumc[i-1]+a[i];
        if(a[i] >= a[i]+maxc[i-1]){
            maxc[i] = a[i];
            s[i] = i;
        } else if(i-s[i-1] < w){
            maxc[i] = a[i]+maxc[i-1];
            s[i] = s[i-1];
        } else {
            int mm = a[i];
            int mi = i;
            for(int j = i-w+1; j < i; j++){
              int si = a[i]+sumc[i-1]-sumc[j-1];
                if(si >= mm){
                    mm = si;
                    mi = j;
                }
            }
            maxc[i] = mm;
            s[i] = mi;
        }
    }

    int mcs = maxc[0];
    for(int i = 1; i < n; i++){
        mcs = max(mcs, maxc[i]);
    }

    cout << mcs;

    return 0;
}
