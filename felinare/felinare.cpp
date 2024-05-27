#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; assert(cin >> n); 
  assert(1 <= n && n <= 100000);
  
  vector<int> dp(n, -1);
  for (int i = 0; i < n; ++i) {
    int fi; assert(cin >> fi);
    assert(0 <= fi && fi <= n);
    int l = max(0, i - fi);
    dp[l] = max(dp[l], i + fi);
  }
  
  int ans = 0, r = -1, maxr = -1;
  for (int i = 0; i < n; ++i) {
    maxr = max(maxr, dp[i]);
    if (r < i) {
      r = maxr;
      ans += 1;
    }
  }
  cout << ans << endl;

  return 0;
}
