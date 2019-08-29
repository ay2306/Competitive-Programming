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
    ull a;
    cin >> a;
    ull sum = 0;
    int arr[5] = {1,5,10,20,100};
    for(int i = 4; i >= 0; --i){
        if(arr[i] <= a){
            sum+=(a/arr[i]);
            a = a%arr[i];
        }
    }
    cout << sum;
    return 0;
}