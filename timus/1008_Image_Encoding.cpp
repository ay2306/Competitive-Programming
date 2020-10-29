#include<bits/stdc++.h>
using namespace std;

void solveType1(int n){
    map<pair<int,int>, int> m;
    queue<pair<int,int>> q;
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        if(q.empty()){
            cout << x << " " << y << "\n";
            q.emplace(x,y);
        }else{
            m[pair<int,int> (x,y)] = 1;
        }
    }
    string d = "RTLB";
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    while(q.size()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int k = 0; k < 4; ++k){
            pair<int,int> p(x+dx[k],y+dy[k]);
            if(m.count(p) == 0)continue;
            m.erase(p);
            q.emplace(p);
            cout << d[k];
        }
        if(q.size())cout << ",\n";
    }
    cout << ".";
}

void solveType2(int x, int y){
    map<char,pair<int,int>> d;
    d['R'] = pair<int,int> (1,0);
    d['T'] = pair<int,int> (0,1);
    d['B'] = pair<int,int> (0,-1);
    d['L'] = pair<int,int> (-1,0);
    set<pair<int,int>> s;
    queue<pair<int,int>> q;
    q.emplace(x,y);
    while(q.size()){
        s.emplace(q.front());
        tie(x,y) = q.front();
        q.pop();
        string a;
        cin >> a;
        for(char i: a){
            if(d.count(i) == 0)continue;
            int X = x + d[i].first;
            int Y = y + d[i].second;
            q.emplace(X,Y);
        }
    }
    cout << s.size() << "\n";
    for(auto i: s){
        cout << i.first << " " << i.second << "\n";
    }
}

int main(){
    string s;
    getline(cin,s);
    int x = 0, y = 0, t = 1;
    for(char i: s){
        if(i == ' ')t++;
        else if(t == 1)x=x*10+i-'0';
        else if(t == 2)y=y*10+i-'0';
    }
    if(t == 1)solveType1(x);
    if(t == 2)solveType2(x,y);
    return 0;
}