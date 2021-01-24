#include<bits/stdc++.h>
using namespace std;

int main(){
    const int N = 3e5;
    int p[N] = {};
    for(int i = 2; i < N; i++){
        if(p[i])continue;
        for(int j = i; j < N; j+=i)p[j] = i;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int a,n;
        scanf("%d",&n);
        map<int,pair<int,int>> range;
        for(int i = 0; i < n; ++i){
            scanf("%d",&a);
            while(a > 1){
                int k = p[a];
                if(range.count(k) == 0)range[k].first = i;
                range[k].second = i;
                while(a % k == 0)a/=k;
            }
        }
        vector<int> diff(n);
        for(auto &i: range)diff[i.second.first]++,diff[i.second.second]--;
        for(int i = 1; i < n; ++i)diff[i] += diff[i-1];
        for(int i = 0; i < n; ++i){
            if(diff[i] == 0){
                printf("%d\n",i+1);
                break;
            }
        }
    }
    return 0;
}