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
    int n;
    cin >> n;
    int c = 0;
    int *a = new int[n];
    int *b = new int[n];
    int *vis = new int[n];
    int *arr = new int[2*n];
    for(int i = 0; i < 2*n; ++i){
        cin >> arr[i];
    }
    for(int i = 0; i < 2*n; i+=2){
        int j;
        for(j = i + 1; arr[j] != arr[i]; ++j);
        while(j-1 != i){
            swap(arr[j],arr[j-1]);
            j--;
            c++;
        }
    }
    cout << c;
    return 0;
}