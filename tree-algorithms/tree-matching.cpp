/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &adj, int v,
         vector<int> &color, int c)
{
  color[v] = c;
  for (int u : adj[v]) {
    if (color[u] == -1) {
      dfs(adj, u, color, (c + 1) % 2);
    }
  }
}

bool dfs(const vector<vector<int>> &adj, int v,
         vector<int> &from)
{
  auto reset = [&] { from[v] = -1; };
  if (from[v] != -1) {
    return false;
  }
  from[v] = v;
  for (int u : adj[v]) {
    if (from[u] == -1 || dfs(adj, from[u], from)) {
      from[u] = v;
      reset();
      return true;
    }
  }
  reset();
  return false;
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
  vector<int> color(n, -1);
  for (int v = 0; v < n; v++) {
    if (color[v] == -1) {
      dfs(adj, v, color, 0);
    }
  }
  vector<int> from(n, -1);
  int result = 0;
  for (int v = 0; v < n; v++) {
    if (color[v]) {
      result += dfs(adj, v, from);
    }
  }
  cout << result;
  return 0;
}
