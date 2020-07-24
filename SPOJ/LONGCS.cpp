#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int> arr;
        string a,b;
        cin >> a;
        a+="$";
        arr.emplace_back(a.size());
        for(int i = 1; i < k; ++i){
            cin >> b;
            b+="$";
            arr.emplace_back(b.size());
            a+=b;
        }
        // cout << a << "\n";
        int mn = *min_element(arr.begin(),arr.end());
        for(int i = 1; i <= k; ++i)arr[i]+=arr[i-1];
        arr.emplace_back(inf);
        multiset<int> min_lcp;
        int f[15] = {};
        int cnt = 0;
        auto sa = suffix_array(a);
        auto lcp = kasai(a,sa);
        function<int(int)> find_string_index = [&arr,&k](int j)->int{
            for(int i = 0; i <= k; ++i){
                if(arr[i] > j)return i;
            }
            return 0;
        };
        int ans = 0;
        for(int i = 1; i <= k; ++i){
            cnt+=f[find_string_index(sa[i])] == 0;
            f[find_string_index(sa[i])]++;
            if(i != k)min_lcp.emplace(lcp[i]);
        }
        if(cnt == k)ans = min(mn,max(ans,*min_lcp.begin()));
        for(int i = k+1; i < a.size(); ++i){
            cnt-=f[find_string_index(sa[i-k])] == 1;
            f[find_string_index(sa[i-k])]--;
            auto it = min_lcp.find(lcp[i-k]);
            min_lcp.erase(it);
            cnt+=f[find_string_index(sa[i])] == 0;
            f[find_string_index(sa[i])]++;
            min_lcp.emplace(lcp[i-1]);
            if(cnt == k)ans = min(mn,max(ans,*min_lcp.begin()));
        }
        ans = min(ans,mn-1);
        cout << ans << "\n";
    }
    return 0;
}