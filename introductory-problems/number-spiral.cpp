//
// Created by Bobur on 14.04.2021
//
#include <bits/stdc++.h>

void solve()
{
    long long x, y;
    std::cin >> x >> y;
    if (x > y)
        if (x % 2) std::cout << ((x - 1) * (x - 1) + y) << std::endl;
        else std::cout << (x * x - y + 1) << std::endl;
    else
        if (y % 2) std::cout << (y * y - x + 1) << std::endl;
        else std::cout << ((y - 1) * (y - 1) + x) << std::endl;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--) solve();
    return 0;
}
