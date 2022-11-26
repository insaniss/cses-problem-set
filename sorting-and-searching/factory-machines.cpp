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
  int n, t;
  cin >> n >> t;
  vector<int> k(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }
  auto test = [&](long long time) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
      count += time / k[i];
    }
    return (long long) t <= count;
  };
  long long left = 0, m, right = 1ll * t *
      *min_element(k.begin(), k.end());
  while (left < right) {
    m = (left + right) / 2;
    if (test(m)) {
      right = m;
    } else {
      left = m + 1;
    }
  }
  cout << left << '\n';
  return 0;
}
