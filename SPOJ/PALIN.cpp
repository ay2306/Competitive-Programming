/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
V<int> num;

bool allNine(string a){
    for(auto i: a)if(i != '9')return false;
    return true;
}

void solve(){
    string a;
    cin >> a;
    int n = a.size();
    if(allNine(a)){
        cout << "1";
        for(int i = 1; i < a.size(); ++i)cout << "0";
        cout << "1\n";
        return;
    }
    num = V<int> ();
    for(auto i: a)num.pb(i-'0');
    /*
    0123
    01234
    */
    int i,j,k;
    i = n/2;
    j = i;
    if(n%2 == 0)i--;
    while(i>=0 && num[i]==num[j]){
        i--;
        ++j;
    }
    if(i < 0 || num[i] < num[j]){
        i = n/2;
        j = i;
        if(n%2 == 0)i--;
        int carry = 1;
        while(i >= 0){
            int k = num[i] + carry;
            carry = k/10;
            num[i] = k%10;
            num[j] = num[i];
            i--;
            ++j;
        }
    }else{
        while(i >= 0){
            num[j] = num[i];
            i--;
            ++j;
        }
    }
    for(auto i: num)cout << i;
    cout << "\n";
}
int main(){
    // FAST
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}