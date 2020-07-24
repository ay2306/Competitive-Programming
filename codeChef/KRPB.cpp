#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod = 998244353;
const int N = 1e6+100;

int p[N];
ll ex[N],ans[N];
vector<pair<ll,ll>> arr[N];

vector<int> suffix_array(string &s)
{
    int n = s.size(), N = n + 256;
    vector<int> sa(n), ra(n);
    for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(int k = 0; k < n; k ? k *= 2 : k++)
    {
        vector<int> nsa(sa), nra(n), cnt(N);
        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
        for(int i = 0; i < n; i++) cnt[ra[i]]++;
        for(int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

        int r = 0;
        for(int i = 1; i < n; i++)
        {
            if(ra[sa[i]] != ra[sa[i - 1]]) r++;
            else if(ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }
    return sa;
}

vector<int> kasai(string &s, vector<int> &sa)
{
    int n = s.size(), k = 0;
    vector<int> ra(n), lcp(n);
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
    }
    return lcp;
}


int findParent(int x){
    if(p[x] < 0)return x;
    p[x] = findParent(p[x]);
    return p[x];
}

void join(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if( a == b )return;
    if(p[a] > p[b])swap(a,b);
    p[a]+=p[b];
    p[b] = a;
}

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    ll p = power(a,n/2);
    p = p * p % mod;
    if(n&1)p = p * a % mod;
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s+="$";
    auto sa = suffix_array(s);
    auto lcp = kasai(s,sa);
    for(int i = 0; i <= n; ++i){
        sa[i] = sa[i+1];
        lcp[i] = lcp[i+1];
    }
    fill(p,p+N,-1);
    for(int i = 1; i <= n; ++i)ex[i] = power(i,k);
    for(int i = 0; i+1 < n; ++i){
        arr[lcp[i]].emplace_back(sa[i],sa[i+1]);
    }
    for(int i = n; i ; i--){
        
    }
    return 0;
}