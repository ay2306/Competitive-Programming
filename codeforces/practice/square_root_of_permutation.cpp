//https://codeforces.com/contest/612/problem/E
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,arr[N],child[N],vis[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
    unordered_map<int,vector<vector<int>>> cycles;
    for(int i = 1; i <= n; ++i){
        if(vis[i])continue;
        vector<int> a(1,i);
        int cur = arr[i];
        while(cur != a[0]){
            a.emplace_back(cur);
            cur = arr[cur];
        }
        for(auto &j: a)vis[j] = 1;
        cycles[(int)a.size()].emplace_back(a);
    }
    for(auto &cyc: cycles){
        if(cyc.first % 2 == 0 && cyc.second.size()%2 == 1)return printf("-1"),0;
        for(auto i = cyc.second.begin(); i != cyc.second.end(); ++i){
            if(cyc.first % 2 == 1){
                for(int k = 0; k < cyc.first; ++k)child[i->at(k)]=i->at((k+(cyc.first+1)/2)%cyc.first);
            }else{
                auto j = i++;
                for(int k = 0; k < cyc.first; ++k){
                    child[j->at(k)] = i->at(k);
                    child[i->at(k)] = j->at((k+1)%cyc.first);
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i)printf("%d ",child[i]);
    return 0;
}