#include<bits/stdc++.h>
using namespace std;
vector<int> suffix_array(string &s){
    int n = s.size(), N = n+256;
    vector<int> sa(n),ra(n);
    for(int i = 0; i < n; ++i)sa[i] = i, ra[i] = s[i];
    for(int k = 0; k < n; k?k*=2:k++){
        vector<int> nsa(sa), nra(n), cnt(N);
        for(auto &i: nsa)i = (i-k+n)%n;
        for(auto &i: ra)cnt[i]++;
        for(int i = 1; i < N; i++)cnt[i]+=cnt[i-1];
        for(int i = n-1; i >= 0; i--)sa[--cnt[ra[nsa[i]]]] = nsa[i];
        int r = 0;
        for(int i = 1; i < n; ++i){
            if(ra[sa[i]] != ra[sa[i-1]])r++;
            else if(ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n])r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }   
    return sa;
}

int main(){
    string a;
    cin >> a;
    a+='\0';
    auto sa = suffix_array(a);
    sa.erase(sa.begin());
    for(auto &i: sa)printf("%d\n",i);
    return 0;
}