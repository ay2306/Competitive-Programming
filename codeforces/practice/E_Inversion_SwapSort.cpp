#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n),b(n);
    for(int &i: a)scanf("%d",&i);
    iota(b.begin(),b.end(),0);
    sort(b.begin(),b.end(),[&](int x, int y)->bool{
        if(a[x] != a[y])return a[x] < a[y];
        return x < y;
    });
    vector<pair<int,int>> ans;
    for(int j = 0; j < n; ++j){
        for(int i = 0; i+1 < n; ++i){
            if(b[i+1] > b[i])continue;
            ans.emplace_back(b[i+1],b[i]);
            swap(b[i],b[i+1]);
        }
    }
    printf("%d\n",(int)ans.size());
    for(auto &[x,y]: ans)printf("%d %d\n",x+1,y+1);
    return 0;
}
