#include<bits/stdc++.h>
using namespace std;

void add(int l, int r, vector<pair<int,int>> &a){
    for(int gap = 1; gap <= r-l; ++gap)
        for(int j = l; j+gap <= r; ++j)a.emplace_back(j,j+gap);
}

int k,u,v;
int main(){
    vector<pair<int,int>> comp1,comp2;
    scanf("%d",&k);
    u = 2*k+3, v = 2*k+4;
    if(k == 1)return printf("YES\n2 1\n1 2"),0;
    if(k % 2 == 0)return printf("NO\n"),0;
    add(1,k+1,comp1);
    add(k+2,2*k+2,comp2);
    for(int i = 0; i < k/2; ++i){
        comp1.emplace_back(u,comp1[0].first);
        comp1.emplace_back(u,comp1[0].second);
        comp2.emplace_back(v,comp2[0].first);
        comp2.emplace_back(v,comp2[0].second);
        comp1.erase(comp1.begin());
        comp1.emplace_back(comp1[0]);
        comp1.erase(comp1.begin());
        comp2.erase(comp2.begin());
        comp2.emplace_back(comp2[0]);
        comp2.erase(comp2.begin());
    }
    comp1.emplace_back(u,v);
    printf("YES\n%d %d\n",2*k+4,(int)comp1.size()+(int)comp2.size());
    for(auto& [x,y]: comp1)printf("%d %d\n",x,y);
    for(auto& [x,y]: comp2)printf("%d %d\n",x,y);
    return 0;
}