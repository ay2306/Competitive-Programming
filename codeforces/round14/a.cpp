#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define V vector
#define P pair
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define C continue;
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define PII pair<int,int>
#define PLL pair<long long, long long>
#define ld long double
#define xx first
#define yy second
#define fst ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 1e9;
const int mod = 1e9+7;

string a[60];

int x1 = inf,x2 = -1, y = inf, y2 = -1;

int main(){
    fst
    int n,m;
    cin >> n >> m;
    loop(i,0,n)cin >> a[i];
    loop(i,0,n){
        loop(j,0,m){
            if(a[i][j] == '*'){
                x1 = min(x1,i);
                y = min(y,j);
                x2 = max(x2,i);
                y2 = max(y2,j);
            }
        }
    }
    loop(i,x1,x2+1){
        loop(j,y,y2+1)cout << a[i][j]; 
        cout << "\n";
    }
    return 0;
}