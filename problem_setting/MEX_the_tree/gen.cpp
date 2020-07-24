#include<bits/stdc++.h>
using namespace std;
int N = 5;
int main(){
    cin >> N;
    freopen("input.txt","w",stdout);
    cout << N << "\n";
    for(int i = 1; i <= N; ++i)cout << N-i << " ";
    cout << "\n";
    for(int i = 2; i <= N; ++i){
        if(i&1)cout << i-2 << " " << i << "\n";
        else cout << i-1 << " " << i << "\n";
    } 
    freopen("output.txt","w",stdout);
    for(int i = 1; i <= N; ++i){
        if(i&1)cout << N-i+1 << "\n";
        else if(i < N) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}