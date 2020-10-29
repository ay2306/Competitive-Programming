#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string cur(100,'a');
        cout << cur << "\n";
        while(n--){
            int x;
            cin >> x;
            cur[x] = cur[x]=='z'?'a':cur[x]+1;
            cout << cur << "\n";
        }
    }
    return 0;
}