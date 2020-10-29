#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    scanf("%d",&n);
    map<int,vector<int>> m;
    vector<int> arr(n),ans(n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        arr[i] = a;
        m[a].emplace_back(i);
    }
    int col = 1;
    for(auto &i: m){
        int same = n - i.first;
        if(i.second.size()%same)return printf("Impossible"), 0;
        int cnt = 0;
        while(i.second.size()){
            ans[i.second.back()] = col;
            i.second.pop_back();
            cnt++;
            if(cnt % same == 0)col++;
        }
    }
    map<int,int> f;
    for(int &i: ans)f[i]++;
    for(int i = 0; i < n; ++i)if(arr[i] != n-f[ans[i]])return printf("Impossible"),0;
    printf("Possible\n");
    for(int i: ans)printf("%d ",i);
    return 0;
}