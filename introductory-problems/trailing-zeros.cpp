//
// Created by Bobur on 15.04.2021
//
#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    int ans = 0, div = 1;
    while (div <= n) {
        div *= 5;
        ans += (n / div);
    }
    std::cout << ans << std::endl;
    return 0;
}
