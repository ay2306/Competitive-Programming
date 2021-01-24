#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n;
    vector<int> a;
    cin >> x;
    while(x--){
        a.emplace_back(0);
        cin >> a.back();
    }
    cin >> x;
    while(x--){
        a.emplace_back(0);
        cin >> a.back();
    }
    sort(a.begin(),a.end());
    if(unique(a.begin(),a.end())-a.begin() == n)cout << "I become the guy.";
    else cout << "Oh, my keyboard!";
    return 0;
}