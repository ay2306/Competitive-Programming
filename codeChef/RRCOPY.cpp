#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<int,int> m;
        for(int i = 1; i <= n; ++i){
            int a;
            cin >> a;
            m[a]++;
        }
        cout << m.size() << "\n";
    }
    return 0;
}