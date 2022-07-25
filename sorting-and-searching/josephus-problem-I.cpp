/*
 *  @author:  octoant
 *  @created: 25.07.2022
 */
#include <iostream>
#include <cassert>

#define parent(i) (i - 1) >> 1
#define left(i)   (i << 1) + 1
#define right(i)  (i << 1) + 2

using namespace std;

const int N = 2e5 + 1;

int tree[4 * N];

void buildtree(int i, int sum, int &leaf) {
  if (sum == 1) {
    tree[i] = --leaf;
  } else {
    buildtree(left(i), (sum + 1) / 2, leaf);
    tree[i] = sum;
    buildtree(right(i), sum / 2, leaf);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  assert(n > 0);
  
  int sum = 1, val = 0;
  buildtree(0, n, val); // segment tree
  for (int i = 0; i < n; i++) {
    sum++;
    while (sum > tree[0]) {
      sum -= tree[0];
    }
    val = sum;
    int tmp, j = 0;
    while (tree[j] > 0) {
      tmp = tree[left(j)];
      if (tmp < 0) {
        tmp = 1;
      }
      tree[j]--;
      if (tmp < val) {
        val -= tmp;
        j = right(j);
      } else {
        j = left(j);
      }
    }
    cout << -tree[j] << " ";
    tree[j] = 0;
  }
  return 0;
}

