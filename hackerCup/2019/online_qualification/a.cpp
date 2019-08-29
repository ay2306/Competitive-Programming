#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T){
        string a;
        cin >> a;
        int cnt = 0;
        for(auto &i: a)cnt+=(i == 'B');
        int mn = ((a.size()-1)/2) + ((a.size()-1)%2);
        int mx = a.size()-2;
        if(a.size() == 1 || (mn <= cnt && mx >= cnt)){
            printf("Case #%d: Y\n",T+1);
        }else{
            printf("Case #%d: N\n",T+1);
        }
    }
    return 0;
}