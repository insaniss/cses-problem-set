//
// Created by Bobur on 14.04.2021
//
#include <bits/stdc++.h>

int main()
{
    long long n;
    std::cin >> n;
    std::cout << n;
    while (n != 1) {
        std::cout << " ";
        if (n % 2) std::cout << (n = 3 * n + 1);
        else std::cout << (n >>= 1);
    }
    return 0;
}
