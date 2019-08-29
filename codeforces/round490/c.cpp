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
    string a;
    cin >> a;
    int j = 0;
    int arr[26] = {0};
    for(int i = 0; i < a.length(); ++i)arr[a[i]-'a']++;
    for(int i = 0; i < 26; ++i){
        if(k >= arr[i]){
            k-=arr[i];
        }else{
            arr[i] = k;
            k = 0;
        }
    }
    // for(int i = 0; i < 26; ++i)cout << arr[i] << "  ";
    // cout << endl;
    for(int i = 0; i < a.length(); ++i){
        if(arr[a[i]-'a'] > 0){
            // cout << arr[a[i]] << "  " << a[i] << endl;
            arr[a[i]-'a']--;
        }else{
            // cout << "CHCK";
            cout << a[i];
        }
    }
    return 0;
}