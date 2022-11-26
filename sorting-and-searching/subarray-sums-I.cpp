/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  int i = 0, answer = 0;
  for (int j = 0; j < n; j++) {
    sum += a[j];
    while (sum > x) {
      sum -= a[i++];
    }
    answer += (sum == x);
  }
  cout << answer << '\n';
  return 0;
}
