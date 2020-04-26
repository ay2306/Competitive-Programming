#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,n1,m1,l=0,r=0,ans=0;
    cin >> n >> m;
    n1 = n-1, m1= m-1;
    if(!n1)l++;
    if(!m1)r++;
    while(n1)l++,n1/=7;
    while(m1)r++,m1/=7;
    if(l+r > 7)return printf("0\n"),0;
    // cout << l << " " << r << "\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            set<int> k;
            int i1 = i, j1 = j, cnt = 0;
            while(i1){k.insert(i1%7);i1/=7;cnt++;}
            while(j1){k.insert(j1%7);j1/=7;cnt++;}
            // for(int i: k)cout << i << " ";
            // cout << endl;
            ans+=((k.size() == l+r) || (k.size() == l+r-1 && k.count(0) == 0 && cnt == k.size()));
        }
    } 
    cout << ans ;
    return 0;
}