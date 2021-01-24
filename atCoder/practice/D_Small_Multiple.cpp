#include<bits/stdc++.h>
using namespace std;
const int N = 1e5, K = 25;
short dp[K][N][46];
int pw[K];
int k, cur;
short cal(int pos, int rem, int sum){
    if(pos == K)return rem == 0 && sum >= 0 && sum < cur;
    if(sum < 0)return 0;
    short &res = dp[pos][rem][sum];
    if(~res)return res;
    res = 0;
    for(int i = 0; i <= 9; ++i){
        res += cal(pos+1,(rem + i*pw[pos]%k)%k, sum-i);
        if(res)return res;
    }
    return 0;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    auto clk = clock();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin >> k;
    // if(k == 99999)return cout << 45,0;
    pw[K-1] = 1;
    for(int i = K-2; ~i; --i)pw[i] = pw[i+1]*10%k;
    int lo = 0, hi = 45, ans = 47;
    while(lo <= hi){
        int mid = lo + hi >> 1;
        cur = mid;
        for(int pos = 0; pos < K; ++pos){
            for(int rem = 0; rem < k; ++rem){
                for(int sum = 0; sum <= mid; ++sum)dp[pos][rem][sum] = -1;
            }
        }
        if(cal(0,0,mid)){
            ans = mid;
            hi = mid-1;
        }else lo = mid+1;
    }
    cout << ans << "\n";
	#ifdef LOCAL
        cout << double(clock() - clk)/CLOCKS_PER_SEC * 1000.0 << "\n";
		// cout << "\n\nTIME ELAPSED : " << double(clock() - clk)/CLOCKS_PER_SEC * 1000.0 << " ms.\n";
	#endif
    return 0;
}  