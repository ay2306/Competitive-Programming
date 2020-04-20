#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
long long calculate(int factor){
    if(factor == 1)return LLONG_MAX;
    long long ans = 0;
    for(int i = 0; i + factor - 1 < arr.size(); i+=factor){
        int med = (i+i+factor-1)>>1;
        for(int j = i; j < i+factor; ++j)ans+=abs(arr[med]-arr[j]);
    }
    return ans;
}

int main(){
    int n,a,s;
    long long ans = LLONG_MAX;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        if(a == 1)arr.emplace_back(i);
    }
    s = arr.size();
    for(int i = 1; i*i <= s; ++i)if(s%i == 0)ans = min({ans,calculate(i),calculate(s/i)});
    if(ans == LLONG_MAX)ans=-1;
    printf("%lld",ans);
    return 0;
}