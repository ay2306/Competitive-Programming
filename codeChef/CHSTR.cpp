#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7, N = 10010; 

long long fact[N], ifact[N];

long long power(long long a, long long n){
	if(n == 0)return 1LL;
	if(n == 1)return a%mod;
	long long p = power(a,n>>1);
	p = p * p % mod;
	if(n & 1)p = p * a % mod;
	return p;
}

void pre(){
	fact[0] = 1;
	ifact[0] = 1;
	fact[1] = 1;
	ifact[1] = 1;
	for(int i = 2; i < N; ++i)fact[i] = i * fact[i-1] % mod, ifact[i] = ifact[i-1] * power(i,mod-2) % mod;
}

long long ncr(long long n, long long r){
	if(r < 0 || r > n)return 0;
	return fact[n] * ifact[r] % mod * ifact[n-r] % mod;
}

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

int solve(){
	int n,q;
	cin >> n >> q;
	long long single = n * 1LL * (n+1) >> 1;
	string s;
    cin >> s;
    s+="$";
    auto sa = suffix_array(s);
    auto lcp = kasai(s,sa);
    lcp.erase(lcp.begin());
    lcp.pop_back();
    stack<int> st;
    vector<vector<int>> P(n+1);
    vector<int> L(n,-1), R(n,n-1);
    vector<long long> cnt(n+10),ans(n+10);
    for(int i = 0; i < lcp.size(); ++i){
        while(st.size() && lcp[st.top()] >= lcp[i])st.pop();
        if(st.size())L[i] = st.top();
        st.push(i);
    }
    while(st.size())st.pop();
    for(int i = n-2; i >= 0; --i){
        while(st.size() && lcp[st.top()] >= lcp[i])st.pop();
        if(st.size())R[i] = st.top();
        st.push(i);
    }
    for(int i = 0; i < lcp.size(); ++i)P[lcp[i]].emplace_back(i);
    for(int V = 1; V <= n; ++V){
        int right = -1;
        for(int i: P[V]){
            if(i < right)continue;
            int v = V;
            if(~L[i])v = min(v,V-lcp[L[i]]);
            if(R[i] != n-1)v = min(v,V-lcp[R[i]]);
            single -= (R[i]-L[i])*1LL*v;
            cnt[R[i]-L[i]] += v;
            right = R[i];
        }
    }
	cnt[1] = single;
	for(int i = 0; i < ans.size(); ++i){
		for(int j = 0; j < ans.size(); ++j)ans[i] = (ans[i] + ncr(j,i) * cnt[j] % mod) % mod;
	}
	while(q--){
		int k ;
		cin >> k;
		if(k > ans.size())cout << 0 << "\n";
		else cout << ans[k] << "\n";
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	pre();
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}