//https://codeforces.com/contest/7/problem/A
#include<bits/stdc++.h>

int a[8][8],ans,col;
std::string g;
int main(){
    for(int i = 0; i < 8; ++i){
        std::cin >> g;
        if(g == "BBBBBBBB")ans++;
        else for(int j = 0; j < 8; ++j)a[i][j] = g[j]=='B';
    }
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j)
            if(a[i][j])col=(col|(1<<j));
    }
    return std::cout << ans+__builtin_popcount(col),0;
}