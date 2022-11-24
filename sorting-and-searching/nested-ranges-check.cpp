/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, y;
  cin >> n;
  vector<array<bool, 2>> res(n);
  vector<array<int, 3>> segment(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    segment[i] = {x, y, i};
  }
  sort(segment.begin(), segment.end(), [](const auto &a, const auto &b) {
    return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
  });
  int s = 0;
  for (auto &[x, y, i] : segment) {
    if (s < y) {
      s = y;
    } else {
      res[i][1] = true;
    }
  }
  reverse(segment.begin(), segment.end());
  s = 1e9 + 7;
  for (auto &[x, y, i] : segment) {
    if (s > y) {
      s = y;
    } else {
      res[i][0] = true;
    }
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < n; i++) {
      cout << res[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
