#include<bits/stdc++.h>
#define MAX 2001
using namespace std;
bitset<MAX> g[MAX],com;
int n;
int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int x;
      cin >> x;
      g[i][j] = x;
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      int count = (g[i] & g[j]).count();
      ans+=((count*(count-1))/2);
    }
  }
  cout << ans/2;
  return 0;
}
