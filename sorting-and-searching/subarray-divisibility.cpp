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
  int n;
  cin >> n;
  vector<int> count(n);
  count[0] = 1;
  long long result = 0;
  int x, s = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s = (s + x) % n;
    s = (s + n) % n;
    result += count[s];
    count[s]++;
  }
  cout << result << '\n';
  return 0;
}
