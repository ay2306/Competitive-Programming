#include<bits/stdc++.h>
using namespace std;

int main(){
    const int N = 3e5+10;
    int cnt = 0,p[N] = {};
    for(int i = 2; i < N; ++i){
        if(p[i])continue;
        cnt++;
        for(int j = i; j < N; j+=i)p[j]++;
    }
    cout << cnt;
    return 0;
}