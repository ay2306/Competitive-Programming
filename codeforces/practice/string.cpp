#include<bits/stdc++.h>
using namespace std;

template<class MAXN>
class SuffixAutomaton{
    struct node{
        int len, link;
        map<char,int> next;
        node():len(0),link(-1){}
    } *tree;
    int last, sz;
public: 
    SuffixAutomaton(){
        sz = 1;
        last = 0;
        tree = new tree[MAXN*2];
    }
    void add(char c){
        int cur = sz++, p = last;
        tree[cur].len = tree[last].len + 1;
        for(; )
    }
};

int main(){

    return 0;
}