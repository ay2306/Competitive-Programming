// Implementation Idea from Scott_wu

#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n,a,ans=0;
    scanf("%lld",&n);
    priority_queue<int> p;
    while(n--){
        scanf("%lld",&a);
        if(p.size() && -p.top() < a){
            ans += a + p.top();
            p.pop();
            p.push(-a);
            p.push(-a);
        }else{
            p.push(-a);
        }
    }
    printf("%lld",ans);
    return 0;
}