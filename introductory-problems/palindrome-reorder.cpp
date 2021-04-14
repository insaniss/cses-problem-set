//
// Created by Bobur on 15.04.2021
//
#include <bits/stdc++.h>

int container[256];
int main()
{
    std::string s;
    std::cin >> s;
    for (char i : s) {
        container[i]++;
    }
    int tmp = 0;
    for (int i : container) {
        if (i % 2) tmp++;
    }
    if (tmp > 1 || (tmp == 1 && !s.length() % 2)) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 'A'; i <= 'Z'; ++i)
        for (int j = 0; j < container[i] >> 1; j++)
            putchar(i);
    for (int i = 'A'; i <= 'Z'; ++i)
        if (container[i] % 2)
            putchar(i);
    for (int i = 'Z'; i >= 'A'; --i)
        for (int j = 0; j < container[i] >> 1; j++)
            putchar(i);
    return 0;
}
