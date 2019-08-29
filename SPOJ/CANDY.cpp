#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == -1)break;
        vector<long> arr(n);
        for(int i = 0; i < n; ++i)cin >> arr[i];
        long sum = accumulate(arr.begin(),arr.end(),0*1LL);
        if(sum % n != 0){
            cout << -1 << "\n";
        }else{
            sum/=n;
            long ans = 0;
            for(long &i: arr){
                if(i > sum)ans+=(i-sum);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}