#include<bits/stdc++.h>
using namespace std;

template<int MAXN>
class SuffixAutomaton{
    struct node{
        int len, link;
        map<char,int> next;
        node():len(0),link(-1){}
    } *tree;
    int last, sz;
    long long *dp;
public:
    SuffixAutomaton(){
        tree = new node[2*MAXN];
        last = 0;
        sz = 1;
        dp = new long long[2*MAXN];
    }
    void add(char c){
        int cur = sz++,p = last;
        tree[cur].len = tree[last].len + 1;
        for(; p != -1 && !tree[p].next.count(c); p = tree[p].link)
            tree[p].next[c] = cur;
        if(p == -1)
            tree[cur].link = 0;
        else{
            int q = tree[p].next[c];
            if(tree[q].len == tree[p].len+1){
                tree[cur].link = q;
            }else{
                int clone = sz++;
                tree[clone].len = tree[p].len + 1;
                tree[clone].next = tree[q].next;
                tree[clone].link = tree[q].link;
                for(; p != -1 && tree[p].next[c] == q; p = tree[p].link)
                    tree[p].next[c] = clone;
                tree[q].link = tree[cur].link = clone;
            }
        }
        last = cur;
    }
    long long distinct(){
        fill(dp,dp+MAXN*2,-1);
        return distinct_cal(0);
    }
    long long distinct_cal(int cur, string a = "", int parent = -1){
        long long &res = dp[cur];
        // cout << a << " " << cur << " " <<  res << "\n";
        if(~res)return res;
        res = (parent != -1);
        for(auto &i: tree[cur].next){
            res+=distinct_cal(i.second,a+i.first,cur);
        }
        return res;
    }
    string dfs(int k, int s = 0, string res = ""){
        if(!k)return res;
        long long left = 0;
        for(auto &i: tree[s].next){
            if(left+dp[i.second] >= k)return dfs(k-1-left,i.second,res+i.first);
            left+=dp[i.second];
        }
        return res;
    }
};

int main(){
    string a;
    cin >> a;
    SuffixAutomaton<100000> s;
    for(char i: a)s.add(i);
    int q;
    cin >> q;
    s.distinct();
    while(q--){
        int k;
        cin >> k;
        cout << s.dfs(k) << "\n";
    }   
    return 0;
}