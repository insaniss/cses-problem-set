//
// Created by Bobur on 01.05.2021
//
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p[200000];
int res[200000];

void dfs(int i)
{
    for (int j : p[i]) {
        dfs(j);
        res[i] += res[j] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1, j; i < n; i++) {
        cin >> j;
        p[j-1].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}
