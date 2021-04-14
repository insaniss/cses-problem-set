//
// Created by Bobur on 14.04.2021
//
#include <bits/stdc++.h>

int n;
int in[200002];

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> in[i];
    }
    long long ans = 0;
    int pnt = in[0];
    for (int i = 0; i < n; i++) {
        if (pnt > in[i]) {
            ans += (pnt - in[i]);
        } else {
            pnt = in[i];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
