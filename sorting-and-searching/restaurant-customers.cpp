//
// Created by Bobur on 26.04.2021
//
#include <bits/stdc++.h>

const int size = 2e5;

int n;
int a[size], b[size];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }
    std::sort(a, a + n);
    std::sort(b, b + n);
    int i = 0, j = 0, res = 0, t = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            t++;
            i++;
        } else {
            t--;
            j++;
        }
        if (res < t) res = t;
    }
    std::cout << res;
    return 0;
}
