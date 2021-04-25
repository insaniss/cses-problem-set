//
// Created by Bobur on 25.04.2021
//
#include <bits/stdc++.h>

const int size = 2e5;

int n, m, k;
int a[size], b[size];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];
    std::sort(a, a + n);
    std::sort(b, b + m);
    int i = 0, j = 0, res = 0;
    while (i < n && j < m) {
        if (a[i] - k <= b[j] && b[j] <= a[i] + k)
            i++, j++, res++;
        else if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
    }
    std::cout << res;
    return 0;
}
