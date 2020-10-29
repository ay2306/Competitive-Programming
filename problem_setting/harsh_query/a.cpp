#include<bits/stdc++.h>
#define int long long
using namespace std;

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

int32_t main(){
	int q;
	cin >> q;
	string s;
	cin >> s;
	s+="$";
	auto sa = suffix_array(s);
	vector<int> prv(s.size(),0);
	int cnt = 0;
	for(int i = 1; i < sa.size(); ++i){
		prv[sa[i]] = cnt;
		cnt+=(s.size()-sa[i]-1);
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << prv[l-1] + (r-l+1) << "\n";
	}
	return 0;
}
