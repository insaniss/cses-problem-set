/*
 *  @author:  octoant
 *  @created: 23.07.2022
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  set<int> uniq;
  int i = 0, j = 0, res = 0;
  while (j < n) {
    while (j < n && !uniq.count(num[j])) {
      uniq.insert(num[j++]);
      if (res < j - i) {
        res = j - i;
      }
    }
    while (j < n && uniq.count(num[j])) {
      uniq.erase(num[i++]);
    }
  }
  cout << res << endl;
  return 0;
}
