//https://codeforces.com/contest/13/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,ans=0;
    scanf("%lld",&n);
    priority_queue<long long> p;
    while(n--){
        scanf("%lld",&a);
        if(p.size() && p.top() > a){
            ans+=p.top()-a;
            p.pop();
            p.push(a);
        }
        p.push(a);
    }
    return printf("%lld\n",ans),0;
}