/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    December, 2022
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  sort(a.begin(), a.end());
  long long time = 0, reward = 0;
  for (auto [x, y] : a) {
    time += x;
    reward += y - time;
  }
  cout << reward << endl;
  return 0;
}
