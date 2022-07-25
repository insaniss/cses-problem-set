/*
 *  @author:  octoant
 *  @created: 25.07.2022
 */
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, n, p;
  cin >> x >> n;

  set<int> points {0, x};
  multiset<int> lengths {x};
  for (int i = 0; i < n; i++) {
    cin >> p;
    auto a = points.lower_bound(p);
    auto b = a--;
    points.insert(p);
    lengths.erase(lengths.find(*b - *a));
    lengths.insert(p - *a);
    lengths.insert(*b - p);
    cout << *lengths.rbegin() << " ";
  }
  return 0;
}

