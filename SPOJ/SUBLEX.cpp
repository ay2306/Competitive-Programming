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

vector<int> kasai(string &s, vector<int> &sa){
    int n = s.size(),k=0;
    vector<int> ra(n),lcp(n);
    for(int i = 0; i < n; ++i)ra[sa[i]] = i;
    for(int i = 0; i < n; ++i){
        if(k)k--;
        if(ra[i] == n-1){k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[(i+k)%n] == s[(j+k)%n])k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]]+1)%n] > ra[(sa[ra[j]]+1)%n])k=0;
    }
    return lcp;
}


int main(){
    string a;
    cin >> a;
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n),ans(n,pair<int,int>(-1,-1));
    for(int i = 0; i < n; ++i)cin >> arr[i].first,arr[i].second = i;
    sort(arr.rbegin(),arr.rend());
    a+="$";
    long long cur = 0;
    auto sa = suffix_array(a);
    auto lcp = kasai(a,sa);
    for(int i = 1; i < a.size() && arr.size();){
        int length = a.length() - (sa[i] + lcp[i-1]) - 1;
        if(cur + length < arr.back().first){
            cur+=length;
            i++;
        }else{
            int ind = arr.back().second;
            int k = arr.back().first;
            ans[ind].first = sa[i];
            ans[ind].second = lcp[i-1] + (k-cur);
            arr.pop_back();
        }
    }
    for(int i = 0; i < n; ++i){
        // cout << ans[i].first << " " << ans[i].second << "\n";
        cout << a.substr(ans[i].first,ans[i].second) << "\n";
    }
    return 0;
}