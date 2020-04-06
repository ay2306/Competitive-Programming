#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; ++test){
        string a,ans=""; int op = 0;
        cin >> a;
        for(int i = 0; i < a.size(); ++i){
            int val = a[i]-'0';
            if(val > op){
                ans+=string(val-op,'(');
                op = val;
            }else if(val < op){
                ans+=string(op-val,')');
                op = val;
            }
            ans+=a[i];
            if(i+1 == a.size()){
                ans+=string(op,')');
            }
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }
}