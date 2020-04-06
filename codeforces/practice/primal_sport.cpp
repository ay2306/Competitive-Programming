//https://codeforces.com/contest/923/problem/A
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int p[N],single[N];
set<int> f;
int main(){
  for(int i = 2; i < N; ++i){
    if(p[i] == 0){
      for(int j = i; j < N; j+=i)p[j]=i;
    }
  }
  int x,k;
  cin >> x;
  k = x;
  for(int i = 4; i <= x; ++i)single[i]=i-p[i]+1;
  while(k > 1){
    int j = p[k];
    while(k%j == 0)k/=j;
    f.insert(j);
  }
  int ans = INT_MAX;
  for(auto &j: f){
    for(int i = x-j+1; i <= x; ++i){
      if(p[i] != i)ans = min(ans,single[i]);
    }
  }
  cout << ans;
  return 0;
}