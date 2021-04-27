//
// Created by Bobur on 26.04.2021
//
#include <bits/stdc++.h>

#define f first
#define s second

int n, x;
std::pair<int, int> p[(int)2e5];

int binary_search(int v) {
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (v > p[m].f) {
            l = m + 1;
        } else if (v < p[m].f) {
            r = m;
        } else {
            return p[m].s;
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> x;
    for (int i = 0, j; i < n; i++) {
        std::cin >> j;
        p[i] = std::make_pair(j, i + 1);
    }
    std::sort(p, p + n);
    int a, b;
    for (int i = 0; i < n; i++) {
        if (x > p[i].f) {
            a = binary_search(x - p[i].f);
            b = p[i].s;
            if (a != b && a != -1) {
                std::cout << a << " " << b;
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE";
    return 0;
}
