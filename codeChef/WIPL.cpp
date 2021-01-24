#include<bits/stdc++.h>
using namespace std;

int main(){
    int mx[4001][4001],used[4001][4001];
    memset(mx,-1,sizeof(mx));
    memset(used,-1,sizeof(used));
    vector<int> h;
    used[0][0] = 0;
    mx[0][0] = 0;
    for(int i = 0; i < h.size(); ++i){
        for(int val = 4000; val >= h[i]; --val){
            mx[i][val] = mx[i-1][val];
            used[i][val] = used[i-1][val];
            if(mx[i-1][val-h[i]] + 1 >= mx[i][val])continue;
            mx[i][val] = mx[i-1][val-h[i]] + 1;
            used[i][val] = h[i];
        }
    }
}