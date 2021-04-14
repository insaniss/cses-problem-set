//
// Created by Bobur on 15.04.2021
//
#include <bits/stdc++.h>

const int mod = 1e9 + 7;
int main()
{
    int n;
    std::cin >> n;
    int ans = 1;
    while (n--) {
        ans = (2 * ans) % mod;
    }
    std::cout << ans << std::endl;
    return 0;
}

