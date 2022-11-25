/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> diameter(const vector<vector<int>> &adj, int v,
                        vector<bool> &mark)
{
  int d = 0, left = 0, right = 0;
  mark[v] = true;
  for (int u : adj[v]) {
    if (!mark[u]) {
      auto p = diameter(adj, u, mark);
      if (d < p.first) {
        d = p.first;
      }
      if (left <= p.second + 1) {
        left = p.second + 1;
        if (left > right) {
          swap(left, right);
        }
      }
    }
  }
  return make_pair(max(d, left + right), max(left, right));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  vector<bool> mark(n, false);
  auto p = diameter(adj, 0, mark);
  cout << max(p.first, p.second);
  return 0;
}
