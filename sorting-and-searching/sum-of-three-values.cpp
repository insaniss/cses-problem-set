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
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first, a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    int l = n - 1;
    for (int j = i + 1; j < n; j++) {
      while (j < l && x < a[i].first + a[j].first + a[l].first) {
        l--;
      }
      if (j < l && x == a[i].first + a[j].first + a[l].first) {
        cout << a[i].second << ' ' << a[j].second << ' ' << a[l].second << '\n';
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}
