#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define ll long long int
using namespace std;

const ll MAX = 87000008;
int arr[MAX];
int main(){
    FAST
    vector<ll> prime;
    for(ll i = 2; i < MAX; ++i)if(arr[i] == 0){
        prime.push_back(i);
        for(ll j = 2; i*j < MAX; ++j)arr[i*j]++;
    }
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        cout << prime[a-1] << endl;
    }
    return 0;
}