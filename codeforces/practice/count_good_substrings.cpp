#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[2][2];
int main(){
    string a;
    cin >> a;
    ll n = a.size();
    ll even = 0;
    ll odd = 0;
    // arr[0][0] counts of 'a' at even position backwards
    // arr[0][1] counts of 'a' at odd position backwards
    // arr[1][0] counts of 'b' at even position backwards
    // arr[1][1] counts of 'b' at odd position backwards
    for(int i = 0; i < n; ++i){
        arr[a[i]-'a'][i&1]++;
        even += arr[a[i]-'a'][(i&1)^1];
        odd += arr[a[i]-'a'][i&1];
    }
    cout << even << " " << odd;
   return 0;
}