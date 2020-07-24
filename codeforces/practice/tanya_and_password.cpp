//https://codeforces.com/contest/508/problem/D
#include<bits/stdc++.h>
using namespace std;


struct node{
    int cnt,indegree;
    string al;
    map<string,node*> child;
    node(string a):al(a),cnt(0),indegree(0){}
};

map<string,node*> ds;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        string first = a.substr(0,2);
        string secon = a.substr(1,2);
        if(ds.count(first) == 0)ds[first] = new node(first);
        if(ds.count(secon) == 0)ds[secon] = new node(secon);
        ds[first]->cnt++;
        ds[first]->child[secon] = ds[secon];
        ds[secon]->indegree++;
    }
    node *cur = nullptr;
    for(auto &i: ds){
        if(!cur || cur->indegree > i.second->indegree)cur=i.second;
    }
    string ans = "";
    while(1){
        bool nextStep = false;
        cout << cur->al << " " << cur->cnt << "\n";
        cur->cnt--;
        for(auto i: cur->child){
            if(i.second->cnt){
                nextStep = true;
                ans+=cur->al[0];
                cur = i.second;
                break;
            }
        }
        if(!nextStep){
            ans+=cur->al;
            break;
        }
    }
    cout << ans << "\n";
    if(ans.size() == n+2)return cout << "YES\n" << ans,0;
    return cout << "NO\n" , 0;
}