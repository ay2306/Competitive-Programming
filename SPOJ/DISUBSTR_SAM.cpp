#include<bits/stdc++.h>
using namespace std;

template<int MAXN>
class SuffixAutomaton{  
    struct node{
        int len,link;
        map<char,int> next;
        node():len(0),link(-1){}
    } *tree;
    int last, sz;
    long long *dp;
public:
    SuffixAutomaton(){
        last = 0;
        sz = 1;
        dp = new long long[MAXN*2];
        tree = new node[MAXN*2];
    }
    void add(char c){
        int cur = sz++,p;
        tree[cur].len = tree[last].len + 1;
        for(p = last; p != -1 && !tree[p].next.count(c); p = tree[p].link)
            tree[p].next[c] = cur;
        if(p == -1)tree[cur].link = 0;
        else{
            int q = tree[p].next[c];
            if(tree[q].len == tree[p].len+1)tree[cur].link = q;
            else{
                int clone = sz++;
                tree[clone].len = tree[p].len + 1;
                tree[clone].next = tree[q].next;
                tree[clone].link = tree[q].link;
                for(; p != -1 && tree[p].next[c] == q; p = tree[p].link){
                    tree[p].next[c] = clone;
                }
                tree[q].link = tree[cur].link = clone;
            }
        }
        last = cur;
    }
    long long distinct(){
        fill(dp,dp+MAXN*2,-1);
        return dfs(0);
    }
    long long dfs(int cur, string a = "", int parent = -1){
        long long &res = dp[cur];
        if(~res)return res;
        res = (parent != -1);
        for(auto &i: tree[cur].next){
            res+=dfs(i.second,a+i.first,cur);
        }
        return res;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        SuffixAutomaton<1010> s;
        for(auto &i: a)s.add(i);
        cout << s.distinct() << "\n";  
    }
    return 0;
}