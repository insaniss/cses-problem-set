//
// Created by Bobur on 20.04.2021
//
#include <bits/stdc++.h>

int n;
int p[20];
long long sum, half;

long long brute_force(int i, long long s)
{
    if (i == -1) return s;
    long long a = brute_force(i - 1, s);
    long long b = brute_force(i - 1, s + p[i - 1]);
    return a > b || b > half ? a : b;
}

int main()
{
    std::cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        sum = sum + p[i];
    }
    half = sum >> 1;
    std::cout << sum - 2 * brute_force(n, 0);
    return 0;
}
