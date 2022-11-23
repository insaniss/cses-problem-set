/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &adj, int s,
         vector<int> &vertex, vector<bool> &mark)
{
  if (mark[s]) {
    return false;
  }
  mark[s] = true;
  for (int t : adj[s]) {
    if (vertex[t] == -1 ||
        dfs(adj, vertex[t], vertex, mark)) {
      vertex[t] = s;
      return true;
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k, a, b;
  cin >> n >> m >> k;
  vector<vector<int>> adj(n);
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
  }
  vector<bool> mark(n);
  vector<int> vertex(m, -1);
  int result = 0;
  for (int i = 0; i < n; i++) {
    fill(mark.begin(), mark.end(), false);
    if (dfs(adj, i, vertex, mark)) {
      result++;
    }
  }
  cout << result << '\n';
  for (int i = 0; i < m; i++) {
    if (vertex[i] != -1) {
      cout << vertex[i] + 1 << ' ' << i + 1 << '\n';
    }
  }
  return 0;
}
