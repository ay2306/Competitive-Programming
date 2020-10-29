#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int k,a,b,v;
    cin >> k >> a >> b >> v;
    int total = 0;
    for(int i = 1; ; ++i){
        int div = max(0LL,min(b,k-1));
        b-=div;
        div++;
        total+=v*div;
        if(total >= a)return cout << i << "\n",0;
    }
    return 0;
}