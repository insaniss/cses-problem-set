/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  set<int> distinct;
  unordered_map<int, int> latest;
  int j = 0;
  long long answer = 0;
  for (int i = 0; i < n; i++) {
    distinct.insert(x[i]);
    latest[x[i]] = i;
    while (k < (int) distinct.size()) {
      if (x[i] != x[j] && latest[x[j]] == j) {
        distinct.erase(x[j]);
      }
      j++;
    }
    answer += i - j + 1;
  }
  cout << answer << endl;
  return 0;
}
