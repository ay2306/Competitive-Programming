//https://codeforces.com/problemset/problem/1200/E
#include<bits/stdc++.h>
using namespace std;

int prefixMatching(string &a, string &b){
    string c = b+"#"+a;
    vector<int> z(c.size(),0);
    for(int i = 1, r = 0, l = 0; i < c.size(); ++i){
        if(i <= r)z[i] = min(z[i-l],r-i+1);
        while(z[i]+i < c.size() && c[z[i]] == c[i+z[i]])++z[i];
        if(i+z[i]-1 > r)l=i,r=i+z[i]-1;
    }
    for(int i = 0; i < c.size(); ++i){
        if(i+z[i] == c.size())return z[i];
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    string ans = a[0];
    for(int i = 1; i < n; ++i){
        if(ans.size() <= a[i].size()){
            int longest = prefixMatching(ans,a[i]);
            ans += a[i].substr(longest,(int)(a[i].size()-longest));
        }else{
            string k = ans.substr((int)ans.size()-(int)a[i].size(),(int)a[i].size());
            int longest = prefixMatching(k,a[i]);
            ans += a[i].substr(longest,(int)(a[i].size()-longest));
        }
    }
    cout << ans << "\n";
    return 0;
}