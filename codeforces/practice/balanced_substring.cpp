#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s=0,ans = 0;
    string a;
    unordered_map<int,int> m;
    m[0] = -1;
    cin >> n >> a;
    for(int i = 0; i < a.size(); ++i){
        s+=(2*(a[i]-'0')-1);
        if(m.count(s))ans=max(ans,i-m[s]);
        else m[s]=i;
    }
    return cout << ans,0;
}