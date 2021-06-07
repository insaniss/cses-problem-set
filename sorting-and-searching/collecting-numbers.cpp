//
// Created by Bobur on 09.05.2021
//
#include <bits/stdc++.h>

using namespace std;

int n;
int idx[200002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i, j = 0; j < n; j++) {
        cin >> i;
        idx[i] = j;
    }
    int i = 1, res = 1;
    while (i < n) {
        i++;
        if (idx[i-1] > idx[i]) res++;
    }
    cout << res << endl;
    return 0;
}