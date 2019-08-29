#include<bits/stdc++.h>
using namespace std;
int n,c;

bool func(int a, vector<int> arr){
    int cw = 1, pos = arr[0];
    for(int i = 1; i < n; ++i){
        if(arr[i]-pos >= a){
            pos = arr[i];
            cw++;
            if(cw == c){
                return true;
            }
        }
    }
    return false;
}

int bs(vector<int> arr){
    int low = 0;
    int high = arr[n-1];
    int ans = -1;
    while(low <= high){
        int mid = (high+low)/2;
        if(func(mid,arr)){
            low = mid+1;
            ans = max(ans,mid);
        }else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> c;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)cin >> arr[i];
        sort(arr.begin(),arr.end());
        cout << bs(arr) << endl;
    }
}