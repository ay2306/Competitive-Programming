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
    int first_odd = 0;
    int second_odd = 0;
    int common_odd = 0;
    PII *a = new PII[n];
    for(int i = 0; i < n; ++i){
        int c,b;
        cin >> c >> b;
        a[i] = mp(c,b);
        if(c%2 == 1){
            first_odd++;
        }
        if(b%2 == 1){
            second_odd++;
        }
        if(c%2 == 1 && b%2 == 1){
            common_odd++;
        }
    }
    // if((first_odd+second_odd)%4 != 0){
    //     cout << "-1";
    //     return 0;
    // }
    if(first_odd == 0 && second_odd % 2 == 0){
        cout << "0";
        return 0;
    }
    if(second_odd%2 == 0 && first_odd == 0){
        cout << "0";
        return 0;
    }
    if(second_odd%2 == 0 && first_odd%2 == 0){
        cout << "0";
        return 0;
    }
    // cout << first_odd << " " << second_odd << " " << common_odd << endl;
    if(first_odd%2 == second_odd%2){
        if(first_odd-common_odd != 0 || second_odd-common_odd!=0){
            cout << "1";
               return 0;
        }
    }
    cout << "-1";

    return 0;
}