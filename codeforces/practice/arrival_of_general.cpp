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

template<typename T>
void pop_front(std::vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}


int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    V<int> l;
    V<int> r;
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(mx < arr[i])mx=arr[i];
        if(mn > arr[i])mn=arr[i];
    }
    for(int i = 0; i < n; ++i){
        if(arr[i] == mx)l.pb(i);
        // if(arr[i] == mn)r.pb(i);
    }
    int c = 0;
    // cout << mx << endl;
    // for(int i = 0; i < l.size(); ++i){
        for(int j = *l.begin(); j > 0; --j){
            // cout << i << " " << j << endl;
            swap(arr[j],arr[j-1]);
            // for(int k = 0; k < n; ++k)cout << arr[k] << " ";
            // cout << endl;
            c++;
        }
    // }
    for(int i = 0; i < n; ++i){
        if(arr[i] == mn)r.pb(i);
    }
    // cout << mn << endl;
    reverse(r.begin(),r.end());
    // for(int i = 0; i < r.size(); ++i){
        for(int j = *r.begin(); j < n-1; ++j){
            // cout << i << " " << j << endl;
            swap(arr[j],arr[j+1]);
            // for(int k = 0; k < n; ++k)cout << arr[k] << " ";
            // cout << endl;
            c++;
        }
    // }
    cout << c;
        
    return 0;
}