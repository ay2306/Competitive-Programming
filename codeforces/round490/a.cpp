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

int main(){
    int n,k;
    cin >> n >> k;
    int *arr = new int[n];
    bool check = false;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(arr[i] > k)check = true;
    }
    int c = 0;
    int s = 0;
    int e = n-1;
    if(!check)c = n;
    while(s <= e && check){
        if(arr[s] <= k){c++;s++;}
        else if(arr[e] <= k){c++;e--;}
        else break;
    }
    cout << c;
    return 0;
}