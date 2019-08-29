#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll k;
ll f(ll n){
  if(n < 0)return 0;
  if(n == 0)return 0;
  if(n == 1)return k-1;
  if(n == 2)return k*(k-1);
  return (k-1)*f(n-1) + (k-1)*f(n-2);
}

int main(){
  ll n;
  cin >> n >> k;
  cout << f(n);
  return 0;
}
