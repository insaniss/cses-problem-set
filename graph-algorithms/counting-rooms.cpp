/*
 *  @author:  octoant
 *  @created: 19.07.2022
 */
#include <iostream>

using namespace std;

int n, m;
string house[1000];

void dfs(string *graph, int i, int j) {
  graph[i][j] = '#';
  if (i > 0 && graph[i - 1][j] == '.') {
    dfs(graph, i - 1, j);
  }
  if (i + 1 < n && graph[i + 1][j] == '.') {
    dfs(graph, i + 1, j);
  }
  if (j > 0 && graph[i][j - 1] == '.') {
    dfs(graph, i, j - 1);
  }
  if (j + 1 < m && graph[i][j + 1] == '.') {
    dfs(graph, i, j + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> house[i];
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (house[i][j] == '.') {
        res++;
        dfs(house, i, j);
      }
    }
  }
  cout << res << endl;
  return 0;
}
