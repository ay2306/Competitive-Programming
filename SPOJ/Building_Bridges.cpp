#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<pair<int,int>> a(n);
        for(auto &i: a)scanf("%d",&i.first);
        for(auto &i: a)scanf("%d",&i.second);
        sort(a.begin(),a.end());
        vector<int> q;
        for(auto &i: a){
            auto it = upper_bound(q.begin(),q.end(),i.second);
            if(it == q.end())q.emplace_back(i.second);
            else *it = i.second;
        }
        printf("%d\n",(int)q.size());
    }
    return 0;
}