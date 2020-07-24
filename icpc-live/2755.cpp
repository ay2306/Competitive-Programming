#include<bits/stdc++.h>
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int N = 5e5+10;
    string s;
    int n,t=1;
    cin >> t;
    while(t--){
        cin >> n >> s;
        // n = s.size();
        s+=s;
        s+='\0';
        auto sa = suffix_array(s);
        auto lcp = kasai(s,sa);
        int ans = 0,id;
        for(int i = 0; i < (int)s.size(); ++i){
            if(sa[i] < n){
                ans = sa[i];
                id = i;
                break;
            }
        }
        for(int i = id+1; i < (int)s.size(); ++i){
            if(lcp[i-1] > n){
                if(sa[i] < ans)ans=sa[i];
            }
            else break;
        }
        cout << ans << "\n";
    }
    return 0;
}