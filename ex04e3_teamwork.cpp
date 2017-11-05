#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> task(m);
    for(int i = 0; i < m; i++){
        scanf("%d", &task[i]);
    }
    sort(task.begin(), task.end());

    double time = 0;
    double t[n] = {};
    for(int i = 0; i < m; i++){
        time += t[i%n] + task[i];
        t[i%n] += task[i];
    }

    printf("%.3f", time/m);

    return 0;
}
