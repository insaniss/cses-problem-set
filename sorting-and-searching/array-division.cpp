/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    December, 2022
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  auto check = [&](long long mid) {
    int segs = 0;
    long long sum = 0;
    for (auto x : a) {
      if (x > mid) {
        return false;
      }
      if (sum + x > mid) {
        segs++;
        sum = 0;
      }
      sum += x;
    }
    if (sum > 0) {
      segs++;
    }
    return segs <= k;
  };
  long long res;
  long long l = 0, m, r = 1e18;
  while (l <= r) {
    m = (l + r) / 2;
    if (check(m)) {
      r = m - 1;
      res = m;
    } else {
      l = m + 1;
    }
  }
  cout << res << endl;
  return 0;
}
