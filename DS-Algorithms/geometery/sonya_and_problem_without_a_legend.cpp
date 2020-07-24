//https://codeforces.com/problemset/problem/713/C
#include<bits/stdc++.h>
using namespace std;

int n,arr[3010];
long long ans = 0;
priority_queue<long long> p;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%d",arr+i);
    for(int i = 0; i < n; ++i)arr[i]-=i;
    for(int i = 0; i < n; ++i){
        if(p.size() && p.top() > arr[i]){
            ans += p.top()-arr[i];
            p.pop();
            p.push(arr[i]);
        }
        p.push(arr[i]);
    }
    printf("%lld",ans);
    return 0;
}