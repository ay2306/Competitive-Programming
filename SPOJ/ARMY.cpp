#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n),b(m);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < m; ++i){
            cin >> b[i];
        }
        if(*max_element(a.begin(),a.end()) >= *max_element(b.begin(),b.end())){
            cout << "Godzilla\n";
        }else{
            cout << "MechaGodzilla\n";
        }
    }
    return 0;
}