//
// Created by Bobur on 25.04.2021
//
#include <bits/stdc++.h>

const int size = 2e5;

typedef std::pair<int, int> pair;

int n, m;
std::multiset<int, std::greater<int>> st;

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;
        st.insert(h);
    }
    for (int i = 0; i < m; i++) {
        int t;
        std::cin >> t;
        auto it = st.lower_bound(t);
        if (it == st.end()) {
            std::cout << -1 << "\n";
        } else {
            std::cout << *it << "\n";
            st.erase(it);
        }
    }
    return 0;
}