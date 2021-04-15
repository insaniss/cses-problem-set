//
// Created by Bobur on 15.04.2021
//
#include <bits/stdc++.h>

void print(std::string &bin, int i)
{
    if (i < 0) return;
    print(bin, i - 1);
    bin[i] = bin[i] == '0' ? '1' : '0';
    std::cout << bin << std::endl;
    print(bin, i - 1);
}

int main()
{
    int n;
    std::cin >> n;
    std::string bin(n, '0');
    std::cout << bin << std::endl;
    print(bin, n - 1);
    return 0;
}
