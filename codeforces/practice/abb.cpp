#include<bits/stdc++.h>
using namespace std;

struct node{
    unordered_map<char,node*> children;
};

class trie{
    node *parent;
public:
    trie(){
        parent = new node();
    }
    void add(string &a){
        node *current = parent;
        for(auto &i: a){
            if(current->children.find(i) == current->children.end()){
                current->children[i] = new node();
            }
            current = current->children[i];
        }
    }
    bool exists(string &a)const{
        node *current = parent;
        for(auto &i: a){
            if(current->children.find(i) == current->children.end()){
                return false;
            }
            current = current->children[i];
        }
        return true;
    }
};

vector<string> topNCompetitors(int numCompetitors, int topN,vector<string> competitors, int numReviews, vector<string> reviews){
    trie *a = new trie();
    for(auto i: competitors){
        a->add(i);
    }
    unordered_map<string,int> cnt;
    for(auto i :reviews){
        trie *b = new trie();
        string cur = "";
        for(int j = 0; j <= i.size(); ++j){
            if(j == i.size() || i[j] == ' '){
                if(a->exists(cur) && !b->exists(cur)){
                    cnt[cur]++;
                    b->add(cur);
                }
                cur = "";
            }else{
                cur+=i[j];
            }
        }
        delete(b);
    }
    set<pair<int,string>> s;
    for(auto i: cnt){
        s.insert(make_pair(i.second,i.first));
        cout << i.second << " " << i.first << "\n";
    }
    vector<string> ans;
    for(int i = 0; i < topN && s.size(); ++i){

        auto it = prev(s.end());
        ans.push_back(it->second);
        s.erase(it);
    }
    return ans;
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    int topR;
    cin >> n >> topR;
    vector<string> comp(n);
    for(int i = 0; i < n; ++i){cin >> comp[i];}
    int sent;
    cin >> sent;
    vector<string> rev(sent);
    cin.ignore();
    for(int i = 0; i < sent; ++i){getline(cin,rev[i]); cout << i << " " << rev[i] << "\n";}
    auto ans = topNCompetitors(n,topR,comp,sent,rev);
    for(auto i: ans)cout << i << "\n";
    return 0;
}