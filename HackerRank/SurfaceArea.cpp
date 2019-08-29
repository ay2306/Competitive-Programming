#include<bits/stdc++.h>
using namespace std;

int ans(vector<vector<int> > a){
    int cost = 0;
    bool someLeft = true;
    do{
        someLeft = false;
        for(int i = 1; i+1 < a.size(); ++i){
            for(int j = 1; j+1 < a[i].size(); ++j){
                if(a[i][j]!=0){
                    if(a[i-1][j] == 0)cost++;
                    if(a[i+1][j] == 0)cost++;
                    if(a[i][j-1] == 0)cost++;
                    if(a[i][j+1] == 0)cost++;
                }
            }
        }
        for(int i = 1; i+1 < a.size(); ++i){
            for(int j = 1; j+1 < a[i].size(); ++j){
                if(a[i][j]!=0){
                    a[i][j]--;
                    if(a[i][j])someLeft = true;
                }
            }
        }
    }while(someLeft);
    // cout << (a.size()-
    cost+=(2*(a.size()-2)*(a[1].size()-2));
    return cost;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > A;
    vector<int> v;
    A.push_back(v);
    for(int i = 0; i-2 < m; ++i)A[0].push_back(0);

    for(int i = 1; i <= n; ++i){
        // vector<int> v;
        A.push_back(v);
        A[i].push_back(0);
        for(int j = 1; j <= m; ++j){
            int a;
            cin >> a;
            A[i].push_back(a);
        }
        A[i].push_back(0);
        // A.push_back(v);
    }
    A.push_back(v);
    for(int i = 0; i-2 < m; ++i)A[A.size()-1].push_back(0);

    // for(int i = 0; i < A.size(); ++i){
    //     for(int j = 0; j < A.size(); ++j){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans(A);
}
