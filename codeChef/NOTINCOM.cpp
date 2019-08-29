#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> a,b;
        int k,n,m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            cin >> k;
            a.push_back(k);
        }
        for(int i = 0; i < m; ++i){
            cin >> k;
            b.push_back(k);
        }
        sort(b.begin(),b.end());
        sort(a.begin(),a.end());
        int j = 0;
        int cnt = 0;
        for(int i = 0; i < a.size(); ++i){
            if(j >= b.size())break;
            if(a[i]==b[j])cnt++;
            if(a[i]<b[j])continue;
            if(a[i]>b[j]){
                while(j<b.size() && b[j]<=a[i]){
                    if(a[i]==b[j]){
                        cnt++;
                        break;
                    }else{
                        j++;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}