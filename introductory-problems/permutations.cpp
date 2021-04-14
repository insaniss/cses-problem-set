//
// Created by Bobur on 14.04.2021
//
#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION" << std::endl;
    } else {
        // 1 2 3 4 -> 2 4 1 3
        for (int i = 2; i <= n; i += 2)
            std::cout << i << " ";
        for (int i = 1; i <= n; i += 2)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}
