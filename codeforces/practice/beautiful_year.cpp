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
bool isBeautiful(int y){
    int arr[10] = {0};
    while(y){
        arr[y%10]++;
        y/=10;
    }
    for(int i = 0; i < 10; ++i){
        if(arr[i] > 1)return false;
    }
    return true;
}

int main(){
    int y;
    cin >> y;
    y++;
    while(!isBeautiful(y))y++;
    cout << y;
    return 0;
}