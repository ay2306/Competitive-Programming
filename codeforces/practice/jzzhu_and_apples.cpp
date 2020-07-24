//https://codeforces.com/contest/449/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int cnt[N],pr[N],used[N];
vector<int> p;
vector<pair<int,int>> ans;
int main(){
    int n;
    scanf("%d",&n);
    if(n <= 3)return printf("0"),0;
    vector<pair<int,int>> ans;
    for(int i = 2; i <= n; ++i){
        if(pr[i] == 0){
            if(i != 2)p.emplace_back(i);
            for(int j = i; j <= n; j+=i)pr[j] = i;
        }
    }
    p.emplace_back(2);
    for(auto &i: p){
        if(i*2 > n)continue;
        vector<int> s;
        for(int j = i; j <= n; j+=i){
            if(!used[j])s.emplace_back(j);
        }
        if(s.size() == 1)continue;
        if(s.size() & 1)s.erase(s.begin()+1);
        for(int j = 1; j < s.size(); j+=2){
            used[s[j]] = 1;
            used[s[j-1]] = 1;
            ans.emplace_back(s[j-1],s[j]);
        }
    }
    printf("%d\n",ans.size());
    for(auto& [x,y]: ans)printf("%d %d\n",x,y);
    return 0;
}