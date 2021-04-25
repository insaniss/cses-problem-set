//
// Created by Bobur on 25.04.2021
//
#include <bits/stdc++.h>

const int size = 2e5;

int n, x;
int p[size];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> x;
    for (int i = 0; i < n; i++)
        std::cin >> p[i];
    std::sort(p, p + n);
    int i = 0, j = n - 1, res = 0;
    while (i <= j) {
        if (p[i] + p[j] > x)
            j--, res++;
        else
            i++, j--, res++;
    }
    std::cout << res;
    return 0;
}
