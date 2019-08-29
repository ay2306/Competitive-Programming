#include <bits/stdc++.h>
#define ll long long int
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;


int main(){
    FILE_READ
    ll n;
    cin >> n;
    vector<int> arr(n+50,0);
    for(int i = 2; i <= n+20; ++i){
        if(arr[i] == 0){
            for(int j = 2; i*j <= n+20; ++j)arr[i*j]++;
        }
    }
    n/=2;
    n++;
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        if(arr[a] == 0){
            if(a >= n)printf("Both\n");
            else printf("Dev\n");
        }else{
            if(a >= n)printf("Ayush\n");
            else printf("None\n");
        }
    }
    return 0;
}