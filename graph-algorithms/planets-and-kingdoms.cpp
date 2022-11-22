/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bfs(const vector<vector<int>> &adj, int s,
         vector<bool> &visited, vector<int> &vertices)
{
  visited[s] = true;
  for (const int v : adj[s]) {
    if (!visited[v]) {
      bfs(adj, v, visited, vertices);
    }
  }
  vertices.push_back(s);
}

void bfst(const vector<vector<int>> &adjt, int s, int color,
          vector<bool> &visited, vector<int> &ans)
{
  visited[s] = true;
  ans[s] = color;
  for (const int v : adjt[s]) {
    if (!visited[v]) {
      bfst(adjt, v, color, visited, ans);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> adjt(n, vector<int>());
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adjt[b].push_back(a);
  }
  vector<int> vertices;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bfs(adj, i, visited, vertices);
    }
  }
  reverse(vertices.begin(), vertices.end());
  fill(visited.begin(), visited.end(), false);
  vector<int> ans(n);
  int color = 0;
  for (const int v : vertices) {
    if (!visited[v]) {
      bfst(adjt, v, ++color, visited, ans);
    }
  }
  cout << color << '\n';
  for (const int item : ans) {
    cout << item << ' ';
  }
  return 0;
}
