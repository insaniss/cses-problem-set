/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> enc, dec;
  for (auto &x : a) {
    cin >> x;
    enc[x] = 0;
  }
  int id = 1;
  for (auto &[key, val] : enc) {
    val = id++;
    dec[val] = key;
  }
  // fenwick tree
  vector<int> tree(n + 1);
  auto add = [&](int x, int val) {
    while (x <= n) {
      tree[x] += val;
      x = x | (x + 1);
    }
  };
  auto sum = [&](int x) {
    int total = 0;
    while (x >= 0) {
      total += tree[x];
      x = (x & (x + 1)) - 1;
    }
    return total;
  };
  int mid = (k + 1) / 2;
  for (int i = 0; i < n; i++) {
    add(enc[a[i]], 1);
    if (i >= k) {
      add(enc[a[i - k]], -1);
    }
    if (i >= k - 1) {
      int l = 1, r = n + 1;
      while (l <= r) {
        int m = (l + r) / 2;
        if (sum(m) >= mid && sum(m - 1) < mid) {
          cout << dec[m] << ' ';
          break;
        }
        if (sum(m) < mid) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
  }
  return 0;
}
