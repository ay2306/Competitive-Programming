#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        string a,ans="";
        cin >> n >> a ;
        for(int i = 0; i < n; ++i)ans+=a[i*2];
        cout << ans << endl;
    }
    return 0;
}