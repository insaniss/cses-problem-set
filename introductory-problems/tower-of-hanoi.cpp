//
// Created by Bobur on 15.04.2021
//
#include <bits/stdc++.h>

void hanoi_move(int n, int a, int b, int c) {
    if (n == 0) return;
    hanoi_move(n - 1, a, c, b);
    std::cout << a << " " << c << std::endl;
    hanoi_move(n - 1, b, a, c);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << (1 << n) - 1 << std::endl;
    hanoi_move(n, 1, 2, 3);
    return 0;
}
