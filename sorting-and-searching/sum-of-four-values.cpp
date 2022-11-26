/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_map<int, pair<int, int>> sum;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int y = a[i] + a[j];
      auto p = sum[x - y];
      if (p.first && p.second <= i) {
        cout << p.first << ' ' << p.second << ' '
          << i + 1 << ' ' << j + 1 << '\n';
        return 0;
      }
      auto q = sum[y];
      if (q.first == 0 || q.second > j) {
        sum[y] = {i + 1, j + 1};
      }
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}
