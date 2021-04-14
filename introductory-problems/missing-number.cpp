//
// Created by Bobur on 14.04.2021
//
#include <bits/stdc++.h>

bool input[200002];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        input[x] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!input[i]) {
            std::cout << i << std::endl;
            break;
        }
    }
    return 0;
}
