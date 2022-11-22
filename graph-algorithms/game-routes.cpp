/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void bfs(const vector<vector<int>> &adj, int u,
         vector<bool> &visited, vector<int> &vertices)
{
  visited[u] = true;
  for (const int v : adj[u]) {
    if (!visited[v]) {
      bfs(adj, v, visited, vertices);
    }
  }
  vertices.push_back(u);
}

vector<int> toposort(const vector<vector<int>> &adj, int s)
{
  vector<int> vertices;
  vector<bool> visited(adj.size(), false);
  bfs(adj, s, visited, vertices);
  reverse(vertices.begin(), vertices.end());
  return vertices;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
  }
  vector<int> vertices = toposort(adj, 0);
  vector<int> sum(n, 0);
  sum[0] = 1;
  for (const int v : vertices) {
    for (const int u : adj[v]) {
      sum[u] = (sum[u] + sum[v]) % MOD;
    }
  }
  cout << sum[n-1] << '\n';
  return 0;
}
