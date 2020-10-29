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

int sum(int l, int r){
    l = l*(l-1)/2;
    r = r*(r+1)/2;
    return r-l;
}

void solve(){
    string s;
    cin >> s;
    s+="$";
    auto sa = suffix_array(s);
    auto lcp = kasai(s,sa);
    /*
        Note: lcp[i] indicates common prefix between suffix sa[i] and sa[i+1]
    */
    int k;
    cin >> k;
    // cout << s.size() << " " << sa.size() << "\n";
    // for(int i : sa)cout << i << " ";
    // cout << endl;
    for(int i = 1; i < sa.size(); ++i){
        int max_length = s.size() - sa[i] - 1;
        int min_length = lcp[i-1] + 1;
        // cout << s.substr(sa[i],max_length) << " " << k << " " << min_length << " " << max_length << "\n";
        // cout << sum(min_length,max_length) << "\n";
        if(min_length > max_length)continue;
        if(sum(min_length,max_length) >= k){
            for(int len = min_length; len <= max_length; ++len){
                if(k > len){
                    k-=len;
                    continue;
                }
                cout << s[sa[i]+k-1] << "\n";
                return;
            }
            break;
        }
        k-=sum(min_length,max_length);
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}