#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0;
    string a;
    cin >> a;
    while(a.size()){
        string k = "";
        while(a.size()){
            k+=a.back();
            a.pop_back();
            if(k.back() != '0')break;
        }
        reverse(k.begin(),k.end());
        if(a.size() < k.size() || (a.size() == k.size() && a < k)){
            ans++;break;
        }else ans++;
    }
    cout << ans ;
    return 0;
}