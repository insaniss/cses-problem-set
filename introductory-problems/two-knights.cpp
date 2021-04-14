//
// Created by Bobur on 14.04.2021
//
#include <bits/stdc++.h>

long long count(int n)
{
    if (n == 1) return 0l;
    if (n == 2) return 6l;
    if (n == 3) return 28l;

    return (n * n * (n * n - 1l) - 8 * (n - 4) * (n - 4) - 40 * (n - 4) - 48) >> 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; ++i) {
        std::cout << count(i) << std::endl;
    }
    return 0;
}
