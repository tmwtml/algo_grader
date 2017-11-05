#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> a(100001);
vector<int> t(100001);

int mergeSort(int l, int r){
    int ans = 0;
    if(l >= r)  return ans;
    int mid = (l+r)/2;
    ans += mergeSort(l, mid);
    ans += mergeSort(mid+1, r);

    int i = l;
    int j = mid+1;
    for(int k = l; k <= r; k++){
        if(i > mid){
            t[k] = a[j++];
        } else if(j > r){
            t[k] = a[i++];
        } else if(a[i] <= a[j]){
            t[k] = a[i++];
        } else {
            ans += mid-i+1;
            t[k] = a[j++];
        }
    }
    for(int k = l; k <= r; k++){
        a[k] = t[k];
    }

    return ans;
}

int main()
{
    int n, x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a[i] = x;
    }

    int m = mergeSort(0, n-1);
    printf("%d", m);

    return 0;
}
