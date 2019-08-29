#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;


int main(){
    int n,m;
    int arr[10] = {0};
    int brr[10];
    cin >> n >> m;
    for(int i = 0,a;i < n; ++i){
        cin >> brr[i];
    }
    for(int i = 0,a;i < m; ++i){
        cin >> a;
        arr[a]++;
    }
    for(int i = 0; i < n; ++i){
        if(arr[brr[i]])cout << brr[i] << " ";
    }
    
    return 0;
}