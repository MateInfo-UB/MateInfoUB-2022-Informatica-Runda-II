#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m; assert(cin >> n >> m);
  assert(1 <= n && n <= 300000);
  assert(1 <= m && m <= 300000);
  assert(m <= 1LL * n * n);
  
  vector<pair<int, int>> pairs;
  for (int i = 0; i < m; ++i) {
    int a, b; assert(cin >> a >> b);
    assert(1 <= a && a <= n);
    assert(1 <= b && b <= n);
    pairs.emplace_back(a - 1, b - 1);
  }
  sort(pairs.begin(), pairs.end());
  assert(unique(pairs.begin(), pairs.end()) == pairs.end());
  
  vector<int> aib(n + 1);
  int j = 0;
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    for (int jp = j; jp < m && pairs[jp].first == i; ++jp) {
      for (int k = pairs[jp].second + 2; k <= n; k += (k & -k))
        total += aib[k];
    }
    for (int jp = j; jp < m && pairs[jp].first == i; ++jp) {
      for (int k = pairs[jp].second + 1; k > 0; k -= (k & -k))
        aib[k] += 1;
    }
    for (int jp = j; jp < m && pairs[jp].first == i; ++jp) {
      j += 1;
    }
  }
  cout << total << endl;

  return 0;
}
