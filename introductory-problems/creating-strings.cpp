//
// Created by Bobur on 24.04.2021
//
#include <bits/stdc++.h>

#define size(s) (int) s.size()
#define all(x) x.begin(), x.end()

int len;
std::string s, permutation;
int chars[256];
bool chosen[8];
std::set<std::string> set;

int fact(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void search()
{
    if (len == size(permutation)) {
        int t = size(set);
        set.insert(permutation);
        if (t < size(set))
            std::cout << permutation << "\n";
    } else {
        for (int i = 0; i < len; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(s[i]);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main()
{
    std::cin >> s;
    len = size(s);
    for (int i = 0; i < len; i++) {
        chars[s[i]]++;
    }
    int result = fact(len);
    for (int i : chars) {
        result /= fact(i);
    }
    std::cout << result << "\n";
    std::sort(all(s));
    search();
    return 0;
}
