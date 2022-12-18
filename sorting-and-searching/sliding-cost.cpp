/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    December, 2022
 */
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
private:
  vector<T> data{};
  int size{};
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  map<int, int> encode;
  vector<int> decode(n + 1);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    encode[a[i]] = 0;
  }
  int id = 0;
  for (auto &[key, value] : encode) {
    value = ++id;
    decode[value] = key;
  }
  fenwick_tree<int> count(n + 1);
  fenwick_tree<long long> prefix(n + 1);
  int mid = (k + 1) / 2;
  for (int i = 0; i < n; i++) {
    count.add(encode[a[i]], 1);
    prefix.add(encode[a[i]], a[i]);
    if (i >= k) {
      int j = i - k;
      count.add(encode[a[j]], -1);
      prefix.add(encode[a[j]], -a[j]);
    }
    if (i >= k - 1) {
      int left = 1, right = n;
      int m, s = 0;
      while (left <= right) {
        m = (left + right) / 2;
        s = count.sum(m);
        if (s >= mid && count.sum(m - 1) < mid) {
          break;
        }
        if (s < mid) left = m + 1;
        else right = m - 1;
      }
      auto a = prefix.sum(m);
      auto b = prefix.sum(n) - a;
      cout << (2 * s - k) * decode[m] - a + b << ' ';
    }
  }
  return 0;
}
