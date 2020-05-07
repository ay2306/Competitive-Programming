#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 505;
const int R = 2e5+10;
const ll inf = 1e18;
ll dp[N][R];
int f[R];

void pre(){
    for(ll i = 1; i < N; ++i){
        if(i == 1){
            dp[i][0] = 1;
            continue;
        }
        ll max_inversions = (i*(i-1))/2;
        for(ll j = 0; j <= max_inversions+1; ++j){
            ll s = 0;
            for(int k = 0; k < i; ++k){
                if(s > inf){
                    s = -1;
                    break;
                }
                if(dp[i-1][j-k] == -1){
                    s = -1;
                    break;
                }
                s+=dp[i-1][j-k];
            }
            if(s > inf)s = -1;
            dp[i][j] = s;
        }
        // sum[0] = dp[i][0]==-1;
        // for(int j -)
    }
}


void solve(){
    int n,r;
    ll k;
    scanf("%d%d%lld",&n,&r,&k);
    if(dp[n][r] < k && dp[n][r] > -1){
        printf("-1\n");
        return;
    }
    vector<int> ans;
    for(int i = n; i >= 1; i--){
        if(i == 1){
            ans.emplace_back(r);
            break;
        }
        for(int j = 0; j < n; ++j){
            if(dp[i-1][r] == -1 or dp[i-1][r] >= k){
                ans.emplace_back(j);
                break;
            }else{
                k-=dp[i-1][r];
                r--;
            }
        }
    }
    for(int &i: ans)printf("%d ",i);
    printf("\n");
}

int main(){
    pre();
    for(int i = 1; i <= 3; ++i){
        cout << i << " ";
        for(int j = 0; j < (i*(i-1))/2 + 1; ++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}    