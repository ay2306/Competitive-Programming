#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v[100100];
    for(int i = 2; i < 100100; ++i)if(v[i].size() == 0)for(int j = 2; i*j < 100100; ++j)v[i*j].push_back(i);
    int dp[100100];
    for(int i = 2; i < 100100; ++i){
        if(v[i].size() == 0){
            dp[i] = i-1;
        }
        else{
            float ans = i;
            for(int j = 0; j < v[i].size(); ++j){
                ans*=(1.0 - (1.0/v[i][j]));
            }
            dp[i] = (int)ans;
        }
    }
    //FOR PROBLEM
    int n,m;
    cin >> n >> m;
    long long sum = 0;
    for(int i = n; i > 1; --i){
        sum+=dp[i];
        if(sum > m){
            break;
        }
    }
    if(sum < m){
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    int cnt = 0;
    for(int i = 1; i <= n && cnt <= m; ++i){
        for(int j = i+1; j <= n && cnt <= m; ++j){
            if(__gcd(i,j)==1){
                cnt++;
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}