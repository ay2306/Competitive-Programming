#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string a;
        char c;
        int ans = 0;
        cin >> a >> c;
        for(char &i: a)ans+=c==i;
        cout << ans << "\n";
    }
    return 0;
}