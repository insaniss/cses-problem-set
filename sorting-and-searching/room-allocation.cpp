/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n;
  vector<array<int, 3>> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    c[i] = {a, b, i};
  }
  sort(c.begin(), c.end());
  using pii = pair<int, int>;
  queue<int> rooms;
  priority_queue<pii, vector<pii>, greater<pii>> queue;
  vector<int> numbers(n);
  int total = 0;
  for (auto &[left, right, i] : c) {
    while (!queue.empty() && queue.top().first < left) {
      rooms.push(queue.top().second);
      queue.pop();
    }
    if (rooms.empty()) {
      numbers[i] = queue.size() + 1;
    } else {
      numbers[i] = rooms.front();
      rooms.pop();
    }
    queue.push(make_pair(right, numbers[i]));
    total = max(total, int(queue.size()));
  }
  cout << total << '\n';
  for (int x : numbers) {
    cout << x << ' ';
  }
  return 0;
}
