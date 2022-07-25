/*
 *  author:  octoant
 *  created: 23.07.2022
 */
#include <iostream>
#include <set>

using namespace std;

const int N = 2e5 + 2;

int n, t, a, b;;
int num[N], pos[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    pos[num[i]] = i;
  }
  pos[n + 1] = n + 1;
  int res = 1;
  for (int i = 1; i < n; i++) {
    res += (pos[i] > pos[i+1]);
  }

  int i, j;
  set<pair<int, int>> idx;
  while (t--) {
    cin >> a >> b;
    idx.insert({num[a] - 1, num[a]});
    idx.insert({num[a], num[a] + 1});
    idx.insert({num[b] - 1, num[b]});
    idx.insert({num[b], num[b] + 1});
    for (auto p : idx) {
      res -= (pos[p.first] > pos[p.second]);
    }
    swap(num[a], num[b]);
    pos[num[a]] = a;
    pos[num[b]] = b;
    for (auto p : idx) {
      res += (pos[p.first] > pos[p.second]);
    }
    idx.clear();
    cout << res << "\n";
  }
  return 0;
}

