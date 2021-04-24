//
// Created by Bobur on 21.04.2021
//
#include <bits/stdc++.h>

bool board[8][8];
int result = 0;
bool col[8], d1[16], d2[16];

void search(int i) {
    if (i == 8) {
        result++;
    } else {
        for (int j = 0; j < 8; j++) {
            if (col[j] || d1[i+j] || d2[7-i+j] || board[i][j]) continue;
            col[j] = d1[i+j] = d2[7-i+j] = true;
            search(i + 1);
            col[j] = d1[i+j] = d2[7-i+j] = false;
        }
    }
}

int main()
{
    std::string s;
    for (int i = 0; i < 8; i++) {
        std::cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '.') board[i][j] = false;
            if (s[j] == '*') board[i][j] = true;
        }
    }
    search(0);
    std::cout << result;
    return 0;
}
