#include<bits/stdc++.h>
using namespace std;

int main(){
   long long n,s;
   scanf("%lld%lld",&n,&s);
   vector<long long> ans(n);
   for(int i = 0; i < n; ++i)ans[i] = 1;
   ans[0] += s-n;    
   return 0;
}