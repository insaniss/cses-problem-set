/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

template <typename T>
class fenwick {
public:
  fenwick(int size) : n(size) {
    bit.resize(n);
  }
  void inc(int x) {
    while (x < n) {
      bit[x]++;
      x = x | (x + 1);
    }
  }
  T sum(int x) {
    T v{};
    while (x >= 0) {
      v += bit[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
  void clear() {
    fill(bit.begin(), bit.end(), 0);
  }
private:
  vector<T> bit;
  int n;
};

const int N = 2e5;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, y;
  cin >> n;
  vector<array<int, 3>> segs(n);
  set<int> points;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    segs[i] = {x, y, i};
    points.insert(y);
  }
  map<int, int> fun;
  int mark = 0;
  for (auto p : points) {
    fun[p] = mark++;
  }
  vector<int> count(n);
  auto Result = [&]() {
    for (auto c : count) {
      cout << c << ' ';
    }
    cout << '\n';
  };
  sort(segs.begin(), segs.end(), [&](auto &a, auto &b) {
    return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
  });
  fenwick<int> tree(N + 1);
  for (auto &[x, y, i] : segs) {
    count[i] = tree.sum(fun[y]);
    tree.inc(fun[y]);
  }
  Result();
  reverse(segs.begin(), segs.end());
  tree.clear();
  for (auto &[x, y, i] : segs) {
    count[i] = tree.sum(N) - tree.sum(fun[y] - 1);
    tree.inc(fun[y]);
  }
  Result();
  return 0;
}
