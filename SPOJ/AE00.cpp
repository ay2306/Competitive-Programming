#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<pair<int,int>,int> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j*j <= i; ++j){
            if(i%j == 0){
                m[make_pair(j,i/j)]++;
            }
        }
    }
    cout << m.size();
    return 0;
}