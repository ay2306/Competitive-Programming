#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

vector<short> num;

int dp[20][2][200];
short vis[20][2][200];
int s;
int cal(short pos, short f, short sum){
    if(pos == num.size())return sum <= s;
    int &res = dp[pos][f][sum];
    if(vis[pos][f][sum])return res;
    vis[pos][f][sum] = 1;
    short lim = 9;
    if(!f)lim = num[pos];
    res = 0;
    for(short i = 0; i <= lim; ++i){
        res += cal(pos + 1, f || (i != lim), sum + i);
    }
    return res;
}

int numTillHere(int x){
    num.clear();
    if(x == 0)return 1;
    while(x){
        num.emplace_back(x%10);
        x/=10;
    }
    reverse(num.begin(),num.end());
    memset(vis,0,sizeof(vis));
    return cal(0,0,0);
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> s;
        int lo = n, hi = 1e19, ans;
        int base = numTillHere(n-1);
        // cout << "base = " << base << "\n";
        while(lo <= hi){
            int mid = (lo >> 1) + (hi >> 1) + (lo % 2 == 1 && hi % 2 == 1);
            int k = numTillHere(mid);
            // cout << "NUM( " << mid << " ) = " << k << "\n";
            if(k > base)ans = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        cout << ans - n << "\n";
    }
    return 0;
}