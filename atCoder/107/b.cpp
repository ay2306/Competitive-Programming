#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    unordered_map<int,int> r,c;
    vector<string> arr;
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] != '.')break;
            if(j+1 == m)r[i]++;
        }
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[j][i] != '.')break;
            if(j+1 == n)c[i]++;
        }
    }
    int i = 0;
    int j = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(r[i] == 0 && c[j] == 0)cout <<  arr[i][j];
        }
        if(r[i] == 0)cout << endl;
    }
    return 0;
}