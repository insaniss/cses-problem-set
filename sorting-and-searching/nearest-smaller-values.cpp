/**
 * @author  Bobur Zakirov (bobur.octo@gmail.com)
 * @date    November, 2022
 */
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n);
  stack<int> s;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    while (!s.empty() && x[s.top()] >= x[i]) {
      s.pop();
    }
    if (s.empty()) {
      cout << 0 << ' ';
    } else {
      cout << s.top() + 1 << ' ';
    }
    s.push(i);
  }
  return 0;
}
