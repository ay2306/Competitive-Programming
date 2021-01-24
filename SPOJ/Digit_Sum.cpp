#include<bits/stdc++.h>
using namespace std;
#define int long long 
string a,b;
int dp[11][100][2];

int cal(string n, int pos, int sum, int flag){
    if(pos >= n.size()) return sum; 

    int res = dp[pos][sum][flag]; 
    if(res != -1) return res;  
    
    int limit = 9;
    if(!flag) limit = n[pos]; 
    
    res = 0;
    for(int i = 0; i <= limit; i++){
        if(flag || i < limit) res += cal(n,pos+1,sum+i,true);
        else res += cal(n,pos+1,sum+i,false);            
    } 
    dp[pos][sum][flag] = res;
    return res; 
}

int digitSum(string x){
    int sum = 0;
    for(int i = 0; i < x.size(); i++){
        sum += x[i];
    }
    return sum;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        	if(a == "-1") return 0;
        for(auto  &i : a) i -= '0';
        for(auto  &i : b) i -= '0';
        memset(dp,-1,sizeof(dp)); 
        int r = cal(b,0,0,0);
        memset(dp,-1,sizeof(dp)); 
        int l = cal(a,0,0,0);
        // cout << r << " " << l << " " << digitSum(a) << "\n";
        cout << r - l + digitSum(a)<< "\n";
    }
    return 0;
}