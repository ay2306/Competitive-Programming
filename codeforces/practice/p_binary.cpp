#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(ll n, ll p){
    if(n <= 0)return false;
    string a = "";
    while(n){
        a+=(n%2 + '0');
        n/=2;
    }

    reverse(a.begin(),a.end());
    vector<int> arr;
    for(auto i: a){

        if(i == '1')arr.push_back(0);
        else{
            (*arr.rbegin())++;
        }
    }
    sort(arr.rbegin(),arr.rend());
    cout << arr.size() << "  " << p << "\n";
    if(arr.size() > p)return false;
    p-=arr.size();
    cout << a << "  " << p << "\n";
    if(p == 0)return true;
    for(auto i: arr){
        int k = 0;
        while(k < i){
            if((p+1)-(1 << (k+1)) < 0){
                p++;
                p-=(1 << k);
                break;
            }
            ++k;
        }
        if(p == 0)return true;
    }
    return false;

}

int main(){
    ll n,p;
    cin >> n >> p;
    int ans = 0;
    int c = 0;
    while(n > 0 && c < 10000){
        n-=p;
        c++;
        ans++;
        if(check(n,ans)){
            cout << ans;
            return 0;
        }
    }
    cout << -1;
    return 0;
}