#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

int mat[3][3] = {{0,0,0},{1,0,0},{0,0,1}};

void multiply(int a[3][3], int b[3][3]){
    int c[3][3];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            c[i][j] = 0;
            for(int k = 0; k < 3; ++k)c[i][j]+=a[i][k]*b[k][j]%mod;
            c[i][j] %= mod;
        }
    }
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            a[i][j] = c[i][j];
}

void power(int a[3][3], int n){
    if(n < 2)return;
    power(a,n>>1);
    multiply(a,a);
    if(n%2 == 1)
        multiply(a,mat);
}

void solve(){
    int a,b,x,n;
    cin >> a >> b >> n >> x;
    a%=mod;
    b%=mod;
    x%=mod;
    mat[0][0] = a;
    mat[0][2] = b;
    if(n == 1)cout << (a*x+b)%mod;
    else{
        int A[3][3];
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                A[i][j] = mat[i][j];
        power(A,n-1);
        int row[3] = {(a*x+b)%mod,x,1};
        int res = 0;
        for(int i = 0; i < 3; ++i)res = (res + row[i] * A[0][i]) % mod;
        cout << res;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}