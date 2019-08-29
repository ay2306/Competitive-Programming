#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> m;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i){
        m[arr[i]]++;
    }
    cout << m.rbegin()->first << " ";
    for(int i = k; i < n; ++i){
        m[arr[i-k]]--;
        m[arr[i]]++;
        if(m[arr[i-k]] == 0)m.erase(arr[i-k]);
        cout << m.rbegin()->first << " ";
    }
    return 0;
}