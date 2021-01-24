#include<bits/stdc++.h>
#define int long long 
using namespace std;

int32_t main(){
    int n,res = 1;
    cin >> n;
    priority_queue<pair<int,int>> p;
    for(int i = 0; i < 10; ++i)p.emplace(40,i),res*=40;
    while(true){
        int pwr,index;
        tie(pwr,index) = p.top();
        int newValue = (res/pwr*(pwr-1));
        if(newValue < n)break;
        p.pop();
        res = newValue;
        p.emplace(pwr-1,index);
    }
    int occ[10];
    while(p.size()){
        occ[p.top().second] = p.top().first;
        p.pop();
    }
    string s = "codeforces";
    for(int i = 0; i < 10; ++i)cout << string(occ[i],s[i]);
    return 0;
}