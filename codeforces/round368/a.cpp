//https://codeforces.com/contest/707/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    // scanf("%d%d",&n,&m);
    cin >> n >> m;
    char c;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> c;
            switch(c){
                case 'C':
                case 'M':
                case 'Y': return printf("#Color"),0;
            }
        }
    }
    return printf("#Black&White\n"),0;
}