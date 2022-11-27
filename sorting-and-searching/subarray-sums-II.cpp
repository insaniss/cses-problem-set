/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_map<long long, int> prefix;
  prefix[0]++;
  long long answer = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    answer += prefix[sum - x];
    prefix[sum]++;
  }
  cout << answer << '\n';
  return 0;
}
