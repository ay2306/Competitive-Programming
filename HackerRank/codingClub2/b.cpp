#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double k = 0;
    for(int i = 0 ; i < n; ++i){
        long long int a;
        cin >> a;
        k+=(log(a));
    }
    long long int l = 1;
    long long int r = 10000000000;
    long long int ans;
    while(l <= r){
        long long int mid = (l+r)/2;
        if((n*log(mid))>k){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}
