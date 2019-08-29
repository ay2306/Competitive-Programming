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
    int arr[3] = {0,0,0};
    string a;
    cin >> a;
    int l = 0;
    for(int i = 0; i < a.length(); ++i){
        if(a[i]>='1' && a[i] <= '3'){arr[a[i]-'1']++;}
    }
    bool pos = false;
    while(arr[0]){
        if(pos){
            cout << "+";
        }else{
            pos = true;
        }
        cout << "1";
        arr[0]--;
    }
    while(arr[1]){
        if(pos){
            cout << "+";
        }else{
            pos = true;
        }
        cout << "2";
        arr[1]--;
    }
    while(arr[2]){
        if(pos){
            cout << "+";
        }else{
            pos = true;
        }
        cout << "3";
        arr[2]--;
    }
    return 0;
}