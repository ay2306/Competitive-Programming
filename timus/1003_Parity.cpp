#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n,a,b,m;
        string s;
        cin >> n >> m;
        if(n == -1)break;
        vector<pair<pair<int,int>,bool>> q;
        while(m--){
            cin >> a >> b >> s;
            q.emplace_back(pair<int,int> (a,b), s[0] == 'o');
        }
        map<int,int> exist,prv,par;
        function<bool(int,int,bool)> add = [&](int l, int r, bool parity){
            if(exist.count(r) == 0){
                exist[r];
                prv[r] = l;
                par[r] = parity;
                return true;
            }
            int i = prv[r];
            if(i == l)return (par[r] == parity);
            if(i < l)return add(i,l-1,par[r]!=parity);
            return add(l,i-1,par[r]!=parity);
        };
        int i;
        for(i = 0 ; i < q.size(); ++i){
            if(!add(q[i].first.first,q[i].first.second,q[i].second)){
                cout << i << "\n";
                break;
            }
        }
        if(i == q.size())cout << q.size() << "\n";
    }
    return 0;
}