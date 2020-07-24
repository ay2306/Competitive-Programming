#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;
    s.emplace(0);
    s.emplace(1);
    s.emplace(2);
    while(1){
        int cur = *prev(s.end()) + *prev(prev(s.end()));
        if(cur > 1000)break;
        s.emplace(cur);
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)cout << (s.count(i) ? "O" : "o");
    return 0;
}