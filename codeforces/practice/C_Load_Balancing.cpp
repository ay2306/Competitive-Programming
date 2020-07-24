#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a)cin >> i;
    int s = accumulate(a.begin(),a.end(),0);
    sort(a.begin(),a.end());
    int ans = 0;
    int extra = s % n;
    s /= n;
    while(a.size()){
        ans += abs(a.back() - (s + (extra-- > 0)));
        a.pop_back();
    }
    cout << ans / 2 ;
    return 0;
}