#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double diag = sqrt(20000.00);
int main(){
  map<pair<int,int>,int> mp;
  int n,m;
  cin >> n >> m;
  int k; 
  cin >> k;
  vector<vector<double>> dp(n+1,vector<double>(m+1,inf));
  while(k--){
    int a,b;
    cin >> a >> b;
    mp[make_pair(a,b)]++;
  }
  dp[0][0] = 0;
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      double a = inf;
      double b = inf;
      double c = inf;
      if(i == 0 && j == 0)continue;
      if(i > 0){
        a = dp[i-1][j] + 100;
      }
      if(j > 0){
        b = dp[i][j-1] + 100;
      }
      if(mp.find(make_pair(i,j)) != mp.end()){
        c = dp[i-1][j-1] + diag;
      }
      dp[i][j] = min(a,min(b,c));
    }
  }
  cout << int(round(dp[n][m]));
  return 0;
}
