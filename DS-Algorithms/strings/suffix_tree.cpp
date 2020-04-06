#include<bits/stdc++.h>
using namespace std;

class suffix_tree{
    struct node
    {
        int l, r, par, link;
        map<char,int> nxt;
        node(int L=0,int R=0, int PAR=-1):
            l(L),r(R),par(PAR),link(-1){}
        int len(){return r-l;}
        int get(char c){
            if(!nxt.count(c))return -1;
            return nxt[c];
        }
    };   
    struct state{
        int v, pos;
        state(int v = 0, int POS = 0):v(v),pos(POS){}
    };
    vector<node> t;
    string s;
    int n;
    int sz;
    state ptr;
public:
    suffix_tree(string &a){
        s = a;
        n = a.size();
    }
    state go(state a, int l, int r){
        while(l < r){
            if(a.pos == t[a.v].len()){
                a = state(t[a.v].get(s[l]),0);
            }
        }
    }
};

int main(){

    return 0;
}