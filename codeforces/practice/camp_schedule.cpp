#include<bits/stdc++.h>
using namespace std;

vector<int> zf(string &s){
    int n = s.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)z[i] = min(z[i-l],r-i+1);
        while(z[i]+i < n && s[z[i]] == s[i+z[i]])z[i]++;
        if(z[i]+i-1 > r){
            r = z[i]+i-1;
            l = i;
        }
    }
    return z;
}

int main(){
    string s,t;
    cin >> s >> t;
    int cnt1[2]={0},cnt2[2]={0};
    for(char &i: s)cnt1[i-'0']++;   
    vector<int> z = zf(t);
    int mx = t.size();
    for(int i = 1; i < t.size(); ++i)if(z[i]+i == t.size())mx = min(mx,int(t.size()-z[i]));
    string k = "";
    for(int i = 0; i < mx; ++i){
        k+=t[t.size()-1-i];
    }
    reverse(k.begin(),k.end());
    for(char &i: t)cnt2[i-'0']++;   
    if(cnt1[0] >= cnt2[0] && cnt1[1] >= cnt2[1]){
        cout << t;
        cnt1[0]-=cnt2[0];
        cnt1[1]-=cnt2[1];
    }
    cnt2[0] = 0;
    cnt2[1] = 0;
    for(char &i: k)cnt2[i-'0']++;   
    while(cnt1[0] >= cnt2[0] && cnt1[1] >= cnt2[1]){
        cout << k;
        cnt1[0]-=cnt2[0];
        cnt1[1]-=cnt2[1];
    }
    for(int i = 0; i < cnt1[0]; ++i)cout << 0;
    for(int i = 0; i < cnt1[1]; ++i)cout << 1;
    return 0;
}