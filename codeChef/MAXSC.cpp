#include<bits/stdc++.h>

using namespace std;

long long int f(){
    int n;
    int a[701][701];
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    int lst = INT_MAX;
    long long int sum = 0;
    for(int i = n-1; i > -1; --i){
        int mx = 0;
        for(int j = 0; j < n; ++j){
            if(a[i][j] > mx && a[i][j]<lst){
                mx = a[i][j];
            }
        }
        if(mx == 0)return -1;
        lst = mx;
        sum+=mx;
    }
return sum;
}

int main(){
int t;
cin >> t;
while(t--){
    cout << f() << "\n";
}

return 0;
}
