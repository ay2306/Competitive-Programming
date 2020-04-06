#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;
bool match(vector<char> &a, vector<char> &b){
    for(int i = 0; i < a.size(); ++i)if(a[i]!=b[i])return false;
    return true;
}
int main(){
    string ok;
    cin >> ok;
    vector<char> a(ok.begin(),ok.end());
    cin >> ok;
    vector<char> b(ok.begin(),ok.end());
    if(a.size() < b.size()){
        cout << "0\n";
        return 0;
    }
    vector<char> c(ok.begin(),ok.end());
    for(int i = 0; i+1 < b.size(); ++i){
        c[i] = a[i];
    }
    int ans = 0;
    for(int i = b.size()-1; i < a.size(); ++i){
        c[b.size()-1] = a[i];
        if(match(b,c)){
            ans++;
            c[b.size()-1] = '#';
        }
        for(int i = 0; i+1 < b.size(); ++i)c[i] = c[i+1];
    }
    cout << ans; 
    return 0;
}