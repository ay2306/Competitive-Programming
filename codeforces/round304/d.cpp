#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long int 
#define mp make_pair
#define pb emplace_back
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define P pair
#define PII pair<int,int>
#define PLL pair<ll,ll>
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << " ";
#define debugn(x) cout << #x << " = " << x << "\n";
#endif
#ifndef LOCAL
#define debug(x) 42;
#define debugn(x) 42;
#endif
#define V vector
#define all(a) a.begin(), a.end()
#define MAX(a) *max_element(all(a));
#define MIN(a) *min_element(all(a));
#define SUM(a) *accumulate(all(a),0LL);
#define C continue
#define R return 
using namespace std;

const int N = 5e6+10;

int pr[N];
ll sum[N];
int solve(){
    int a,b;
    cin >> a >> b;
    cout << sum[a]-sum[b] << "\n";
    R 0;
}

int main(){
    loop(i,2,N){
        if(pr[i])continue;
        for(int j = i; j < N; j+=i)pr[j] = i;
    }
    loop(i,2,N){
        int k = i;
        while(k > 1){
            sum[i]++;
            k/=pr[k];
        }
    }
    loop(i,1,N)sum[i]+=sum[i-1];
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}