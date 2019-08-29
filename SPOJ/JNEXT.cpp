#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int *arr = new int[n];
    int *ans = new int[n];
    stack<int> s;
    for(int i = 0; i < n; ++i)cin >> arr[i];
    for(int i = n-1; i >= 0; --i){
        while(s.size() && arr[s.top()] > arr[i]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(s.size()){
        ans[s.top()] = -1;
        s.pop();
    }
    int a = -1;
    int a_i = 0;
    for(int i = 0; i < n; ++i){
        if(ans[i] != -1){
            if(a < ans[i]){
            a_i = i;
            a = ans[i];}
        }
    }
    if(a == -1)cout << a << endl;
    else{
        swap(arr[a_i],arr[a]);
        sort(arr+a+1,arr+n);
        for(int i = 0; i < n; ++i)cout << arr[i];
        cout << endl;
    }
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}