#include<bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        for(int &i: a)scanf("%d",&i);
        sort(a.begin(),a.end());
        a.resize(unique(a.begin(),a.end()) - a.begin());
        bool ans = true;
        for(int i = 1; i < a.size(); ++i)ans = ans && (a[i] == a[i-1] + 1);
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}