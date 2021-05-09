//
// Created by Bobur on 09.05.2021
//
#include <bits/stdc++.h>

using namespace std;

int n, x[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    long long res = 1;
    for (int i = 0; i < n; i++)
        if (res >= x[i]) res += x[i];
        else return cout << res, 0;
    cout << res;
    return 0;
}
