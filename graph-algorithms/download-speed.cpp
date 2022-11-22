/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18L;

void dfs(const vector<vector<long long>> &adj, int s,
    vector<bool> &visited, vector<int> &parent)
{
  visited[s] = true;
  for (int t = 0; t < (int) adj.size(); t++) {
    if (!visited[t] && adj[s][t] > 0) {
      parent[t] = s;
      dfs(adj, t, visited, parent);
    }
  }
}

long long max_capacity(const vector<vector<long long>> &adj, int s, int t,
    const vector<bool> &visited, const vector<int> &parent)
{
  if (!visited[t]) {
    return 0L;
  }
  long long capacity = INF;
  for (int v = t; v != s; v = parent[v]) {
    if (capacity > adj[parent[v]][v]) {
      capacity = adj[parent[v]][v];
    }
  }
  return capacity;
}

long long max_flow(vector<vector<long long>> &adj, int s, int t)
{
  vector<bool> visited(adj.size());
  vector<int> parent(adj.size());
  long long capacity, result = 0;
  do {
    fill(visited.begin(), visited.end(), false);
    dfs(adj, s, visited, parent);
    capacity = max_capacity(adj, s, t, visited, parent);
    if (capacity) {
      for (int v = t; v != s; v = parent[v]) {
        adj[v][parent[v]] += capacity;
        adj[parent[v]][v] -= capacity;
      }
      result += capacity;
    }
  } while (capacity);
  return result;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b;
  long long c;
  cin >> n >> m;
  vector<vector<long long>> adj(n, vector<long long>(n, 0L));
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a - 1][b - 1] += c;
  }
  cout << max_flow(adj, 0, n - 1);
  return 0;
}
