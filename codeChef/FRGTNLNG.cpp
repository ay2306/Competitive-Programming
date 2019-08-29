#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    int *arr = new int[n];
    map<string,int> m;
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        arr[i] = 0;
        m.insert(make_pair(a,i));
    }
    for(int i = 0; i < k; ++i){
        int b;
        cin >> b;
        while(b--){
            string a;
            cin >> a;
            if(m.count(a) != 0){
                arr[m.find(a)->second] = 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(arr[i])cout << "YES ";
        else cout << "NO ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}