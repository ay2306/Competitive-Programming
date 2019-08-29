#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m,x,y,c=0;
    cin >> m >> x >> y;
    int *arr = new int[101];
    for(int i = 0; i <= 101; ++i)arr[i] = 0;
    int a;
    for(int i = 0; i < m; ++i){
        cin >> a;
        arr[a] = 1;
        for(int j = 0; j <= (x*y) && a+j < 101 ; ++j)arr[a+j]=1;
        for(int j = 0; j <= (x*y) && a-j > 0 ; ++j)arr[a-j]=1;
    }
    for(int i = 1; i <= 100; ++i)if(!arr[i])c++;
    cout << c << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}