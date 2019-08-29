#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string a;
        cin >> a;
        // cout << k << endl;
        int *arr = new int[a.length()];
        int j = k;
        arr[0] = 0;
        // cout << "CAS\n";
        for(int i = 1; i < k; ++i){
            // cout << i << endl;
            if(a[i] == a[i-1])arr[i]=0;
            else{
                // cout << a[i] << " " << a[i-1] << endl;
                if(i+k < a.length())arr[i] = i;
                else arr[i] = a.length()-i-1;
            }
        }
        // int i;
        // cout << "CASE2\n";
        for(int i = k; i < n-k; ++i){
            // cout << i << endl;
            if(a[i] == a[i-1])arr[i]=0;
            else{
                arr[i] = k;
            }
        }
        // cout << "CASE3\n";
        int i = n-k;
        if(i < k)i=k;
        for(; i < n; ++i,--j){
            // cout << i <<  endl;
            if(a[i] == a[i-1])arr[i]=0;
            else{
                arr[i] = a.length()-i;
                // arr[i] = j;
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; ++i)ans+=arr[i];
        // for(int i = 0; i < n; ++i)cout << arr[i] << " ";
        // cout << endl;
        cout << ans;
        if(t)cout << endl;
    }
    return 0;
}