/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool reachable(const vector<vector<int>> &adj, int s, int t,
               vector<bool> &visited, vector<int> &path)
{
  fill(visited.begin(), visited.end(), false);
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u = 0; u < (int) adj.size(); u++) {
      if (!visited[u] && adj[v][u]) {
        path[u] = v;
        q.push(u);
        visited[u] = true;
      }
    }
  }
  return visited[t];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a - 1][b - 1] = adj[b - 1][a - 1] = 1;
  }
  vector<bool> visited(n);
  vector<int> path(n);
  while (reachable(adj, 0, n - 1, visited, path)) {
    int flow = 1e9;
    for (int v = n - 1; v != 0; v = path[v]) {
      flow = min(flow, adj[path[v]][v]);
    }
    for (int v = n - 1; v != 0; v = path[v]) {
      adj[path[v]][v] -= flow;
      adj[v][path[v]] += flow;
    }
  }
  vector<pair<int, int>> res;
  for (int v = 0; v < n; v++) {
    for (int u = 0; u < n; u++) {
      if (visited[v] && !visited[u] && adj[u][v]) {
        res.emplace_back(v + 1, u + 1);
      }
    }
  }
  cout << res.size() << '\n';
  for (auto &[v, u] : res) {
    cout << v << ' ' << u << '\n';
  }
  return 0;
}
