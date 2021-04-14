//
// Created by Bobur on 15.04.2021
//
#include <bits/stdc++.h>

void solve()
{
    int a, b;
    std::cin >> a >> b;
    if ((a + b) % 3 == 0 && 2 * a - b >= 0 && 2 * b - a >= 0)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}
