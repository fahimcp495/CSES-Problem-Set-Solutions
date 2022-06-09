
#include<bits/stdc++.h>
using namespace std;
 
// #include "debug.h"
 
using ll = long long;
 
vector<int> a;
 
ll solve(int l, int r) {
  if (l >= r)  return 0;
 
  int m = (l + r) / 2;
  ll ret = solve(l, m) + solve(m + 1, r);
 
  int i = l, j = m + 1;
  while (i <= m or j <= r) {
    if (j > r or (i <= m and a[i] < a[j]))  i++;
    else  j++, ret += m - i + 1;
  }
  inplace_merge(a.begin() + l, a.begin() + m + 1, a.begin() + r + 1);
 
  return ret;
}
 
int solve2(vector<int> p) {
  int n = p.size();
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] == -1)  continue;
    int j = i, len = 0;
    while (p[j] != -1) {
      len++;
      int k = j;
      j = p[j];
      p[k] = -1;
    }
    ans += len - 1;
  }
  return ans;
}
 
int solve3(vector<int> p) {
  int n = p.size();
  vector<int> sorted;
 
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(sorted.begin(), sorted.end(), p[i]);
    if (it == sorted.end()) {
      sorted.push_back(p[i]);
    }
    else {
      *it = p[i];
    }
  }
 
  return n - sorted.size();
}
 
int solve4(vector<int> p) {
  int n = p.size(), cur = n - 1, ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (p[i] == cur)  cur--;
    else  ans++;
  }
  return ans;
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
 
  int n;  cin >> n;
  vector<int> p(n);
  for (auto &pi: p) {
    cin >> pi;  pi--;
  }
 
  a = p;
 
  cout << solve(0, n - 1) << " " << solve2(p) << " " << solve3(p) << " " << solve4(p);
 
}
