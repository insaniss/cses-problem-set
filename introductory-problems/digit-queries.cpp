//
// Created by Bobur on 24.04.2021
//
#include <bits/stdc++.h>

typedef long long ll;

void solve()
{
    ll n;
    std::cin >> n;
    ll t = 9, s = 0, d = 1;
    while (n >= t * d) s += t, n -= t * d, t *= 10, d++;
    if (n % d)
        std::cout << (s + n / d + 1) / (long long) std::pow(10, d - n % d) % 10 << "\n";
    else
        std::cout << (s + n / d) % 10 << "\n";
}

int main()
{
    int times;
    std::cin >> times;
    while (times--) solve();
    return 0;
}
