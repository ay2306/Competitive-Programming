#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int *arr = new int[n];
        int *ans = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            ans[i] = 0;
        }
        for(int i = 0; i < n; ++i){
            int rsum = 0;
            int lsum = 0;
            int l = i-1;
            int r = i+1;
            while(r < n && rsum <= arr[i]){
                ans[r]++;
                r++;
                if(r > i+1)rsum+=arr[r-1];
            }
            while(l >= 0 && lsum <= arr[i]){
                ans[l]++;
                l--;
                if(l < i-1)lsum+=arr[l+1];
            }
        }
        for(int i = 0; i < n; ++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}