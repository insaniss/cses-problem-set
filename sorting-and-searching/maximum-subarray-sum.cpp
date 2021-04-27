//
// Created by Bobur on 27.04.2021
//
#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    long long x, sum = 0, res = 0;
    bool pos = false;
    long long min = -1e9;
    while (t--) {
        std::cin >> x;
        if (min < x) min = x;
        if (sum + x < 0) sum = 0;
        else sum += x, pos = true;
        if (res < sum) res = sum;
    }
    if (!pos) std::cout << min;
    else std::cout << res;
    return 0;
}
