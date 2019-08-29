#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    vector<int> arr,q;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i = 0; i < n; ++i){
        int index = lower_bound(q.begin(),q.end(),arr[i]) - q.begin();
        if(index == q.size())q.push_back(arr[i]);
        else q[index] = arr[i];
    }
    cout << q.size();
    return 0;
}