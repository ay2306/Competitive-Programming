#include<bits/stdc++.h>
using namespace std;

int main(){
    map<vector<string>,int> dis;
    queue<vector<string>> q;
    dis[vector<string> (4, string(4,'w'))] = 0;
    q.emplace(vector<string> (4, string(4,'w')));
    dis[vector<string> (4, string(4,'b'))] = 0;
    q.emplace(vector<string> (4, string(4,'b')));
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    auto get = [](char x)->char{return x == 'w' ? 'b' : 'w';};
    auto valid = [](int i, int j)->bool{return i >= 0 && i < 4 && j >= 0 && j < 4;};
    while(q.size()){
        vector<string> a = q.front();
        vector<string> par = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                a[i][j] = get(a[i][j]);
                for(int k = 0; k < 4; ++k){
                    int x = i + dx[k], y = j + dy[k];
                    if(valid(x,y))a[x][y] = get(a[x][y]);
                }
                if(dis.count(a) == 0){
                    dis[a] = dis[par] + 1;
                    q.emplace(a);
                }
                a = par;
            }
        }
    }
    vector<string> a(4);
    for(int i = 0; i < 4; ++i)cin >> a[i];
    if(dis.count(a) == 0)cout << "Impossible";
    else cout << dis[a];
    return 0;
}