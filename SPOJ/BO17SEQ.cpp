#pragma Optimize("O3")
#include<bits/stdc++.h>
#define node pair<long long,pair<int,int>>
#define mp make_pair
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<long long> arr(n);
    for(auto &i: arr)scanf("%lld",&i);
    set<node> s;
    vector<int> leftPointer(n,-1);
    vector<int> rightPointer(n,-1);
    for(int i = 0; i+1 < n; ++i){
        s.emplace(max(arr[i],arr[i+1]),mp(i,i+1));
        leftPointer[i+1] = i;
        rightPointer[i] = i+1;
    }
    long long ans = 0;
    while(s.size()){
        auto k = *s.begin();
        s.erase(s.begin());
        ans += k.first;
        if(arr[k.second.first] > arr[k.second.second]){
            if(rightPointer[k.second.second] == -1)continue;
            long long cst = max(arr[k.second.second],arr[rightPointer[k.second.second]]);
            auto p = s.find(node(cst,mp(k.second.second,rightPointer[k.second.second])));
            if(p == s.end())continue;
            s.emplace(max(arr[k.second.first],arr[p->second.second]),mp(k.second.first,p->second.second));
            rightPointer[k.second.first] = p->second.second;
            leftPointer[p->second.second] = k.second.first;
            s.erase(p);
        }else{
            if(leftPointer[k.second.first] == -1)continue;
            long long cst = max(arr[leftPointer[k.second.first]],arr[k.second.first]);
            auto p = s.find(node(cst,mp(leftPointer[k.second.first],k.second.first)));
            if(p == s.end())continue;
            s.emplace(max(arr[k.second.second],arr[p->second.first]),mp(p->second.first,k.second.second));
            leftPointer[k.second.second] = p->second.first;
            rightPointer[p->second.first] = k.second.second;
            s.erase(p);
        }
    }
    printf("%lld",ans);
    return 0;
}