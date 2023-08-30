#include<bits/stdc++.h>

using namespace std;
int n, m;
string s[505];
void Solve(){
  cin >> n >> m;
  int cnta[505] = {{0}}, cntb[505] = {{0}};
  bool flag = 0;
  for (int i = 1; i <= n; i++){
    cin >> s[i];
    s[i] = ' ' + s[i];
    for (int j = 1; j <= m; j++){
      cntb[i] += s[i][j] != '.';
    }
    if (cntb[i] % 2){
      flag = 1;
    }
  }
  for (int i = 1; i <= m; i++){
    for (int j = 1; j <= n; j++){
      cnta[i] += s[j][i] != '.';
    }
    if (cnta[i] % 2){
      flag = 1;
    }
  }
  if (flag){
    cout << "-1\n";
    return ;
  }
  for (int i = 1; i <= n; i++){
    int cnt = 0;
    for (int j = 1; j <= m; j++){
      if (s[i][j] != '.'){
        if (s[i][j] == 'L'){
          if (cnt < cnta[i] / 2 && cnt < cntb[j] / 2){
            s[i][j] = 'W', s[i][j + 1] = 'B';
            cnt++;
          }else {
            s[i][j + 1] = 'W', s[i][j] = 'B';
            cnt++;
          }
        }else if (s[i][j] == 'U'){
          if (cnt < cnta[i] / 2 && cnt < cntb[j] / 2){
            s[i][j] = 'W', s[i + 1][j] = 'B';
            cnt++;
          }else {
            s[i + 1][j] = 'W', s[i][j] = 'B';
            cnt++;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cout << s[i][j];
    }
    cout << '\n';
  }
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--){
    Solve();
  }
  return 0;
}