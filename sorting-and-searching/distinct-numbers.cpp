//
// Created by Bobur on 25.04.2021
//
#include <bits/stdc++.h>

int n;
std::set<int> st;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        st.insert(x);
    }
    std::cout << st.size();
    return 0;
}
