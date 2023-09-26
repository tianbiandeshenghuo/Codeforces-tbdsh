#include<bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
int n, q, a[MAXN], b[MAXN], c[MAXN];
void Solve(){
  cin >> n;
  int last = 1;
  b[n + 1] = 1e9 + 1;
  c[n + 1] = n;
  for (int i = 1; i <= n; i++){
    c[i] = n;
    cin >> a[i];
    b[i] = (a[i] & a[i - 1]);
    if (!b[i]){
      for (int j = last; j < i; j++){
        c[j] = i;
      }
      last = i + 1;
    }
  }
  for (int i = 1; i <= n; i++){
    cerr << c[i] << " \n"[i == n];
  }
  for (int i = 1; i <= n; i++){
    cerr << b[i] << " \n"[i == n];
  }
  cin >> q;
  while (q--){
    int l, k;
    cin >> l >> k;
    bool flag = 1;
    for (int i = c[l + 1]; i >= l; i--){
      //cout << i << ' ' << b[i] << '\n';
      if (b[i] >= k){
        flag = 0;
        cout << i << ' ';
        break;
      }else if (i == l && b[l] >= k){
        cout << i << ' ';
        flag = 0;
        break;
      }
    }
    if (flag){
      cout << "-1 ";
    }
  }
  cout << '\n';
}
int main(){
  //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  a[0] = (1ll << 30) - 1;
  int t;
  cin >> t;
  while (t--){
    Solve();
  }
  return 0;
}