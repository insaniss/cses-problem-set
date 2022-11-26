/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  long long m = *max_element(t.begin(), t.end());
  long long sum = accumulate(t.begin(), t.end(), 0ll);
  if (sum - m <= m) {
    cout << 2ll * m << '\n';
  } else {
    cout << sum << '\n';
  }
  return 0;
}
