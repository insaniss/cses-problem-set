/*
 *  @author:  octoant
 *  @created: 24.07.2022
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> k;
  int val;
  for (int i = 0, j = 0; i < n; i++) {
    cin >> val;
    int m, l = 0, r = (int) k.size();
    while (l < r) {
      m = (l + r) / 2;
      if (k[m] <= val) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    if (l != (int) k.size()) {
      k[l] = val;
    } else {
      k.push_back(val);
    }
  }
  cout << k.size() << endl;
  return 0;
}
