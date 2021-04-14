//
// Created by Bobur on 14.04.2021
//
#include <bits/stdc++.h>

int main()
{
    std::string str;
    std::cin >> str;

    int ans = 0, cnt = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i-1] == str[i]) {
            cnt++;
        } else {
            if (ans < cnt) ans = cnt;
            cnt = 1;
        }
    }
    if (ans < cnt) ans = cnt;
    std::cout << ans << std::endl;
    return 0;
}
