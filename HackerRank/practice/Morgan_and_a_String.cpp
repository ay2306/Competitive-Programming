#include<bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string &s){
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

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        a = a + "$" + b + "$";
        auto sa = suffix_array(a);
        vector<int> A(n),B(m);
        for(int i = 0; i < sa.size(); ++i){
            if(sa[i] < n)A[sa[i]] = i;
            if(sa[i] > n && sa[i] != a.size()-1)B[sa[i]-n-1] = i;
        }
        string ans = "";
        int i = 0, j = 0;
        while(i < n || j < m){
            if(i == n)ans+=b[j++];
            else if(j == m)ans+=a[i++];
            else{
                if(A[i] < B[j])ans+=a[i++];
                else ans+=b[j++];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
