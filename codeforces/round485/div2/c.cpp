#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;
const int N = 3030;
ll arr[N][2];
ll ans = LLONG_MAX;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[j][i];
        }
    }
    for(int i = 0; i < n; ++i){
        ll b = -1;
        ll cost = arr[i][1];
        for(int j = 0; j < i; ++j){
            if(arr[j][0] >= arr[i][0])continue;
            if(b == -1 || arr[b][1] > arr[j][1]){
                b = j;
            }
        }
        if(b == -1)continue;
        cost+=arr[b][1];
        b = -1;
        for(int j = i+1; j < n; ++j){
            if(arr[j][0] <= arr[i][0])continue;
            if(b == -1 || arr[b][1] > arr[j][1]){
                b = j;
            }
        }
        if(b == -1)continue;
        cost+=arr[b][1];
        ans = min(ans,cost);        
    }
    if(ans == LLONG_MAX)cout << "-1";
    else cout << ans;
return 0;
}