#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    queue<int> q[4];
    for(int i = 0; i < n; ++i){
        int a1 = a[i]-'0';
        int a2 = b[i]-'0';
        int k = a2*2+a1;
        q[k].push(i+1);
    }
    //0 : nothing
    //1 : CLOWN
    //2 : ACROBAT
    //3 : BOTH
    vector<int> ans;
    if(q[3].size()%2 == 1){
        if(q[1].size()){
            ans.push_back(q[1].front());
            q[3].pop();
            q[1].pop();
        }else if(q[2].size()){
            ans.push_back(q[3].front());
            q[3].pop();
            q[2].pop();
        }else{
            cout << "-1";
            return 0;
        }
    }
    if(q[0].size()%2 == 1){
        if(q[1].size()){
            ans.push_back(q[0].front());
            q[0].pop();
            q[1].pop();
        }else if(q[2].size()){
            ans.push_back(q[2].front());
            q[0].pop();
            q[2].pop();
        }else{
            cout << "-1";
            return 0;
        }
    }
    for(int i = 0; i < 4; ++i){
        if(q[i].size() % 2 == 1){
            cout << "-1";
            return 0;
        }
    }
    while(q[0].size()){
        ans.push_back(q[0].front());
        q[0].pop();
        q[0].pop();
    }
    while(q[3].size()){
        ans.push_back(q[0].front());
        q[0].pop();
        q[0].pop();
    }
    while(q[2].size()){
        ans.push_back(q[2].front());
        q[2].pop();
    }
    if(ans.size() != n/2){
        cout << "-1";
        return 0;
    }
    for(auto i: ans)cout << i << " ";
}