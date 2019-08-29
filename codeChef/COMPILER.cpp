#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int ct = 0;
        int ans = 0;
        int j;
        for(j = 0; j < a.size(); ++j){
            char i = a[j];
            if(i == '<')ct++;
            else{
                if(ct == 0){
                    cout << ans << "\n";
                    break;
                }
                if(ct == 1){
                    ans = j+1;
                }
                ct--;
            }
        }
        if(j == a.size())cout << a.size() << "\n";
    }
    return 0;
}