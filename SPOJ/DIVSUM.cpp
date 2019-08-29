#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[500100] = {0};
    for(int i = 1; i < 500100; ++i)for(int j = 1; i*j < 500100; ++j)arr[i*j]+=i;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << arr[n]-n << endl;
    }
    return 0;
}