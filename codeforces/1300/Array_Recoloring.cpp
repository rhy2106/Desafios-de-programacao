#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    long long ans = 0;
    if (k > 1) {
      sort(a.begin(), a.end(), greater<int>());
      ans = accumulate(a.begin(), a.begin() + k + 1, 0LL);
    } else {
      int l = *max_element(a.begin(), a.end() - 1);
      int r = *max_element(a.begin() + 1, a.end());
      ans = max(l + a.back(), r + a[0]);
    }
    cout << ans << '\n';
  }
}
