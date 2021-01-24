#include<bits/stdc++.h>
using namespace std;
/*
  ..
...
...
..

*/
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    ans.emplace_back(0,0); 
    ans.emplace_back(0,1); 
    ans.emplace_back(0,2); 
    ans.emplace_back(1,1); 
    ans.emplace_back(1,0); 
    ans.emplace_back(1,2); 
    ans.emplace_back(2,0); 
    ans.emplace_back(2,1); 
    ans.emplace_back(2,2); 
    n--;
    while(n--){
        int x,y;
        tie(x,y) = ans.back();
        ans.emplace_back(x+2,y+1);
        ans.emplace_back(x+1,y+2);
        ans.emplace_back(x+1,y+1);
    }
    cout << ans.size() << "\n";
    for(auto i: ans)cout << i.first << " " << i.second << "\n";
    return 0;
}