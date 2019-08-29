#include<bits/stdc++.h>
using namespace std;

int editDis(string a, string b){
    vector<vector<int> > dp (a.length()+1,vector<int> (b.length()+1,0));
    for(int i = 0; i <= a.length(); ++i){
        for(int j = 0; j <= b.length(); ++j){
            if(i == 0 && j == 0)dp[i][j] = 0;
            else if(i == 0)dp[i][j] = j;
            else if(j == 0)dp[i][j] = i;
            else if(a[i-1] == b[j-1])dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
        }
    }
    return dp[a.length()][b.length()];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        cout << editDis(a,b) << "\n";
    }
    return 0;
}