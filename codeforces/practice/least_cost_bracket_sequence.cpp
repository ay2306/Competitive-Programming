//https://codeforces.com/contest/3/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
long long cost;
int a[N],b[N],cnt,opened,ind=-1;
set<pair<int,int>> k;
string s;

int main(){
    cin >> s;
    for(char &i: s)cnt+=i=='?';
    vector<pair<int,int>> arr(cnt);
    for(auto& [x,y]: arr)cin >> x >> y;
    reverse(arr.begin(),arr.end());
    if((int)s.size() & 1)return cout << "-1\n",0;
    for(auto &i: s){
        ind++;
        if(i == '('){
            opened++;
            continue;
        }
        else if(i == ')')opened--;
        else{
            opened--;
            i = ')';
            tie(a[ind],b[ind]) = arr.back();
            arr.pop_back();
            k.emplace(a[ind]-b[ind],ind);
            cost+=b[ind];
        }  
        if(opened < 0){
            if(k.size() == 0)return cout << -1,0;
            opened+=2;
            s[k.begin()->second] = '(';
            cost+=k.begin()->first;
            k.erase(k.begin());
        }
    }
    if(opened != 0)return cout << -1,0;
    return cout << cost << "\n" << s ,0;
}