#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> tmp_vec;
        vector<int> *vec = new vector<int>[n];
        for(int i = 0; i < n; ++i){
            int a,b;
            cin >> a >> b;
            tmp_vec.push_back(make_pair(a,b));
        }
        sort(tmp_vec.begin(),tmp_vec.end());
        for(int i = 0; i < n; ++i){
            for(int j = tmp_vec[i].first; j <= tmp_vec[i].second; ++j)vec[i].push_back(j);
        }
        int q;
        cin >> q;
        for(int some_var = 0; some_var < q; ++some_var){
            int m;
            cin >> m;
            int a;
            vector<int> arr;
            int cnt = 0;
            for(int i = 0; i < m; ++i){
                cin >> a;
                arr.push_back(a);
            }
            sort(arr.begin(),arr.end());
            int cnt = 0;
            for(int i = 0; i < n; ++i){
                int a = 0;
                int b = m-1;
                if(!(arr[m-1]<vec[i][0] || arr[0]>vec[i][vec[i].size()-1])){
                    while(arr[a]<vec[i][0] || arr[b]>vec[i][vec[i].size()-1]){
                        if(arr[a]<vec[i][0])a++;
                        if(arr[b]>vec[i][vec[i].size()-1])b--;
                    }
                    int ct = b-a;
                    if(ct%2==0)cnt++;
                }
            }
            cout << cnt << endl;

        }
    }
return 0;
}

