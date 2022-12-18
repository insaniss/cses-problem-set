/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    December, 2022
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template<typename T>
class fenwick_tree {
public:
  fenwick_tree(int n) : size(n) {
    data.resize(n);
  }
  void add(int x, T v) {
    while (x < size) {
      data[x] += v;
      x = x | (x + 1);
    }
  }
  T sum(int x) {
    T v{};
    while (x >= 0) {
      v += data[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
  int get(T s) {
    int l = 0, m, r = size;
    while (l <= r) {
      m = (l + r) / 2;
      if (sum(m) >= s && (m == 0 || sum(m - 1) < s)) {
        return m;
      }
      if (sum(m) < s) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return -1;
  }
private:
  vector<T> data;
  int size;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  map<int, int> f;
  for (auto &[x, y] : a) {
    cin >> x >> y;
    f[x] = 0, f[y] = 0;
  }
  sort(a.begin(), a.end());
  int id = 0;
  for (auto &[k, v] : f) {
    v = id++;
  }
  int result = 0;
  fenwick_tree<int> tree(2 * n);
  tree.add(0, k);
  for (auto [x, y] : a) {
    int i = tree.get(1);
    int j = tree.get(k);
    if (i <= f[x]) {
      result++;
      tree.add(i, -1);
      tree.add(f[y], 1);
    } else if (j > f[y]) {
      tree.add(j, -1);
      tree.add(f[y], 1);
    }
  }
  cout << result << endl;
  return 0;
}
