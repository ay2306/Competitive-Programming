#include<bits/stdc++.h>
using namespace std;

template<int MAXN>
class SuffixAutomaton{
    struct node{
        int len,link;
        map<char,int> next;
        node():len(0),link(-1){}
    } *tree;
    int last , sz ;
public:
    SuffixAutomaton(){
        tree = new node[MAXN*2];
        last = 0;
        sz = 1;
    }
    void add(char c){
        int cur = sz++, p = last;
        tree[cur].len = tree[last].len + 1;
        for(; p != -1 && !tree[p].next.count(c); p = tree[p].link)
            tree[p].next[c] = cur;
        if(p == -1)tree[cur].link = 0;
        else{
            int q = tree[p].next[c];
            if(tree[q].len == tree[p].len + 1){
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
    int LCS(string &t){
        int v = 0, l = 0, best = 0, bestpos = 0;
        for(int i = 0; i < t.size(); ++i){
            while(v && !tree[v].next.count(t[i])){
                v = tree[v].link;
                l = tree[v].len;
            }
            if(tree[v].next.count(t[i])){
                v = tree[v].next[t[i]];
                l++;
            }
            if(l > best){
                best = l;
                bestpos = i;
            }
        }
        return best;
    }

};

int main(){
    SuffixAutomaton<250100> s;
    string a , b;
    cin >> a >> b;
    for(char i: a)s.add(i);
    cout << s.LCS(b) << "\n";
    return 0;
}