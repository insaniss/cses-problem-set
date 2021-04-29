//
// Created by Bobur on 27.04.2021
//
#include <bits/stdc++.h>

const int size = 2e5;

int n;
long long p[size];

long long calc_sum(long long avg)
{
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += std::abs(avg - p[i]);
    }
    return sum;
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    std::sort(p, p + n);
    long long m;
    if (n & 1) {
        m = p[n / 2];
    } else {
        m = (p[n / 2] + p[n / 2 - 1]) / 2;
    }
    std::cout << calc_sum(m);
    return 0;
}
