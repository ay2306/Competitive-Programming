#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	int n;
  ll k;
  cin >> k >> n;
  vector<ll>  a(n);
  for(auto &i: a)cin >> i;
  sort(a.begin(),a.end());
  ll ans = a[n-1]-a[0];
  for(int i = 1; i < n; ++i)ans = min(ans,a[i-1]+k-a[i]);
  cout << ans;
  return 0;
}
