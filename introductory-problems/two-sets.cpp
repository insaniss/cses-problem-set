//
// Created by Bobur on 15.04.2021
//
#include <bits/stdc++.h>

bool used[1000001];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long sum = 1l * n * (n + 1) / 2;
    if (sum % 2)
        return std::cout << "NO\n", 0;
    sum >>= 1;
    int cnt = 0;
    for (int i = n; i > 0; --i) {
        cnt++;
        if (sum > i) {
            used[i] = true;
            sum -= i;
        } else {
            used[sum] = true;
            break;
        }
    }
    std::cout << "YES" << std::endl;

    std::cout << n - cnt << std::endl;
    for (int i = 1; i <= n; ++i)
        if (!used[i]) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << cnt << std::endl;
    for (int i = 1; i <= n; ++i)
        if (used[i]) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

