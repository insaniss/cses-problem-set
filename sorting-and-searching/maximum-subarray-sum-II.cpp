/*
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    December, 2022
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n >> a >> b;
  vector<long long> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (i > 0) {
      x[i] += x[i - 1];
    }
  }
  multiset<long long> s;
  long long result{};
  for (int i = 0; i < n; i++) {
    if (i >= a) { s.insert(x[i - a]); }
    if (i > b) { s.erase(s.find(x[i - 1 - b])); }
    if (i < a) {
      result = x[i];
    } else if (i < b) {
      result = max(result, x[i] - min(0ll, *s.begin()));
    } else {
      result = max(result, x[i] - *s.begin());
    }
  }
  cout << result << endl;
  return 0;
}