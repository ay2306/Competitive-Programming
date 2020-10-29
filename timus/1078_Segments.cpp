#include<bits/stdc++.h>
#define PII pair<int,int>
#define x first
#define y second
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<pair<PII,int>> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d",&a[i].x.x,&a[i].x.y);
        a[i].y = i;
    }
    sort(a.begin(),a.end());
    vector<int> dp(n,1);
    vector<int> p(n,-1);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(a[j].x.y > a[i].x.y && a[j].x.x < a[i].x.x){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
            }
        }
    }
    int index = max_element(dp.begin(),dp.end()) - dp.begin();
    vector<pair<PII,int>> ans;
    while(~index){
        ans.emplace_back(a[index]);
        index = p[index];
    }
    printf("%d\n",(int)ans.size());
    sort(ans.begin(),ans.end(),[&](pair<PII,int> a, pair<PII,int> b)->bool{
        int l1 = a.x.y - a.x.x;
        int l2 = b.x.y - b.x.x;
        return l1 < l2;
    });
    for(auto i: ans)printf("%d ",i.y+1);
    return 0;
}