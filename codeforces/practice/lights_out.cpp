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
    int arr[3][3];
    for(int i = 0; i < 3; ++i)for(int j = 0; j < 3; ++j)arr[i][j]=1;
    for(int i = 0,a; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            // for(int k = 0; k < 3; ++k){
            //     for(int l = 0; l < 3; ++l){
            //         cout << arr[k][l];
            //     }
            //     cout << endl;
            // }
            // cout << i+1 << " " << j+1 << endl;  
            cin >> a;
            a = a%2;
            arr[i][j]+=a;
            if(i + 1 < 3)arr[i+1][j]+=a;
            if(i - 1 >= 0)arr[i-1][j]+=a;
            if(j + 1 < 3)arr[i][j+1]+=a;
            if(j - 1 >= 0)arr[i][j-1]+=a;
            // if(i + 1 < 3 && j + 1 < 3)arr[i+1][j+1]+=a;
            // if(i + 1 < 3 && j - 1 >= 0)arr[i+1][j-1]+=a;
            // if(i - 1 >= 0 && j + 1 < 3)arr[i-1][j+1]+=a;
            // if(i - 1 >= 0 && j - 1 >= 0)arr[i-1][j-1]+=a;
        }
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout << arr[i][j]%2;
        }
        cout << endl;
    }
    return 0;
}