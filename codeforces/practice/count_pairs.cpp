//https://codeforces.com/problemset/problem/1188/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;
ll n, a, ans, k , p;
map<int,int> m;
int main(){
    scanf("%lld%lld%lld",&n,&p,&k);
    while(n--){
        scanf("%lld",&a);
        ll i = (a%p*a%p*a%p - k + p)%p*a%p;
        ans+=m[i];
        m[i]++;
    }
    printf("%lld",ans);
    return 0;
}