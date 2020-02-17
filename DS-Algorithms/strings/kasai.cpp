#include<bits/stdc++.h>
using namespace std;

struct suffix{
    int index;
    int rank[2];
    bool operator<(suffix &r){
        return (rank[0] < r.rank[0] || (rank[0]==r.rank[0] && rank[1] < r.rank[1]));
    }
};


vector<int> buildSA(string &txt){
    int n = txt.size();
    vector<suffix> s(n);
    vector<int> ind(n);
    for(int i = 0; i < n; ++i){
        s[i].index = i;
        s[i].rank[0] = txt[i]-'a';
        s[i].rank[1] = ((i+1) < n)?(txt[i+1]-'a'):-1;
    }
    sort(s.begin(),s.end());
    for(int k = 4; k < 2*n; k*=2){
        // * INT RANK
        int r = 0;
        // * INT PREVIOUS_RANK
        int pr = s[0].rank[0];
        s[0].rank[0] = r;
        ind[s[0].index] = 0;
        for(int i = 1; i < n; ++i){
            if(s[i].rank[0] == pr && s[i].rank[1] == s[i-1].rank[1]){
                pr = s[i].rank[0];
                s[i].rank[0] = r;
            }else{
                pr = s[i].rank[0];
                s[i].rank[0] = ++r;
            }
            ind[s[i].index] = i;
        }
        for(int i = 0; i < n; ++i){
            // * INT NEXT_INDEX
            int ni = s[i].index + k/2;
            s[i].rank[1] = (ni < n)?s[ind[ni]].rank[0]:-1;
        }
        sort(s.begin(),s.end());
    }
    vector<int> sa;
    for(auto &i: s)sa.emplace_back(i.index);
    return sa;
}

vector<int> kasai(string &s, vector<int> &sa){
    int n = s.size(),k=0;
    vector<int> lcp(n,0),r(n,0);
    for(int i = 0; i < n; ++i)r[sa[i]] = i;
    for(int i = 0; i < n; ++i){
        if(r[i] == n-1){
            k = 0;
            continue;
        }
        int j = sa[r[i]+1];
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k])k++;
        lcp[r[i]] = k;
        k = max(k-1,0);
    }
    return lcp;
}

int main(){
    string a;
    cin >> a;
    auto k = buildSA(a);
    for(auto i: k)cout << i << " ";
    auto j = kasai(a,k);
    cout << "\n";
    for(auto i: j)cout << i << " ";

    return 0;
}