/*
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    December, 2022
 */
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < 6; i++) {
    a[i] = 1;
  }
  int total = 1;
  for (int i = 1; i < n; i++) {
    a[i] = (total + a[i]) % MOD;
    total = (total + a[i]) % MOD;
    if (i >= 6) {
      total = (total - a[i - 6] + MOD) % MOD;
    }
  }
  cout << a[n - 1] << endl;
  return 0;
}