#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string> arr;

int check(int i, int j){
    int res = 0;
    //right
    if(j+3 < m && arr[i][j+1] =='a' && arr[i][j+2] == 'b' && arr[i][j+3] == 'a')res++;
    //left
    // if(j-3 >= 0 && arr[i][j-1] =='a' && arr[i][j-2] == 'b' && arr[i][j-3] == 'a')res++;
    //down
    if(i+3 < n && arr[i+1][j] =='a' && arr[i+2][j] == 'b' && arr[i+3][j] == 'a')res++;
    //up
    // if(i-3 >= 0 && arr[i-1][j] =='a' && arr[i-2][j] == 'b' && arr[i-3][j] == 'a')res++;
    //di-left up
    // if(i-3 >= 0 && j-3 >= 0 && arr[i-1][j-1] =='a' && arr[i-2][j-2] == 'b' && arr[i-3][j-3] == 'a')res++;
    //di-left up
    if(i-3 >= 0 && j+3 < m && arr[i-1][j+1] =='a' && arr[i-2][j+2] == 'b' && arr[i-3][j+3] == 'a')res++;
    //di-left up
    // if(i+3 < n && j-3 >= 0 && arr[i+1][j-1] =='a' && arr[i+2][j-2] == 'b' && arr[i+3][j-3] == 'a')res++;
    // di-left up
    if(i+3 < n && j+3 < m && arr[i+1][j+1] =='a' && arr[i+2][j+2] == 'b' && arr[i+3][j+3] == 'a')res++;
    return res;
}

int main(){
    cin >> n >> m;
    arr = vector<string> (n,"");
    for(int i = 0; i < n; ++i)cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] == 's')ans+=check(i,j);
        }
    }
    cout << ans;
    return 0;
}
