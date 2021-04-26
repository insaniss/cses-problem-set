//
// Created by Bobur on 26.04.2021
//
#include <bits/stdc++.h>

int n;
std::pair<int, int> movie[(int)2e5];

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> movie[i].first >> movie[i].second;
    }
    std::sort(movie, movie + n);
    int p = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (p <= movie[i].first) {
            res++;
            p = movie[i].second;
        }
        if (p > movie[i].second) p = movie[i].second;
    }
    std::cout << res;
    return 0;
}
