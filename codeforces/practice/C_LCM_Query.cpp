#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int N = 2e4+10, M = 17;
const long long mod = 1e9+7;
const int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,49,53,59};
ld ln[M];
int mx[N],n,q,A[N],a,arr[N][M];
long long ans[N];

struct SparseTable{
    int cnt[N][M],prime;
    SparseTable(){}
    SparseTable(int prime):prime(prime){
        for(int i = 0; i < n; ++i){
            cnt[i][0] = arr[i][prime];
        }
        for(int len = 2, k = 1; len <= n; len*=2, k++){
            for(int i = 0; i + len <= n; ++i){
                cnt[i][k] = max(cnt[i][k-1],cnt[i+len/2][k-1]); 
            }
        }
    }
    int query(int l, int r){
        int j = (int)log2(r-l+1);
        return max(cnt[l][j],cnt[r-(1<<j)+1][j]);
    }
}sp[M];

long long power(long long a, long long n){
    if(n == 0 || a == 1)return 1;
    if(n == 1)return a;
    long long p = power(a,n>>1);
    p = p * p % mod;
    if(n&1)p = p * a % mod;
    return p;
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        A[i] = a;
        for(int j = 0; j < M; ++j){
            int cnt = 0;
            while(a%p[j] == 0){
                a/=p[j];
                cnt++;
            }
            arr[i][j]+=cnt;
        }
    }
    for(int i = 0; i < M; ++i)sp[i] = SparseTable(i);
    for(int i = 0; i < M; ++i)ln[i] = log2(p[i]);
    for(int len = 1; len <= n; ++len){
        ld mx = 1e10;
        int mxi;
        for(int i = 0; i < n; ++i){
            int j = i+len-1;
            if(j >= n)break;
            ld s = 0;
            for(int k = 0; k < M; ++k){
                int amx = sp[k].query(i,j);
                s += ln[k]*(ld)amx;
            }
            if(s < mx){
                mxi = i;
                mx = s;
            }
        }
        ans[len] = 1;
        for(int k = 0; k < M; ++k){
            int mx = sp[k].query(mxi,mxi+len-1);
            ans[len] = ans[len] * power(p[k],mx) % mod;
        }
        // cout << endl;
    }
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]) ;
    }
    return 0;
}