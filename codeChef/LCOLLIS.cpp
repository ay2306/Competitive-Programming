#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string a;
        int *arr = new int[m];
        for(int i = 0; i < m; ++i)arr[i] = 0;
        for(int i = 0; i < n; ++i){
            cin >> a;
            for(int j = 0; j < m; ++j){
                if(a[j]=='1')arr[j]++;
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            if(arr[i]>1){
                cnt+=(((arr[i])*(arr[i]-1))/2);
            }
        }
        cout << cnt << endl;
    }
return 0;
}