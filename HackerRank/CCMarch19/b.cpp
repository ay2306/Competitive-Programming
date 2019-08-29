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

const ll maxn = 1e5;

ll squareDist(PLL a, PLL b){
    return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

bool isSquare(PLL p1, PLL p2, PLL p3, PLL p4){
   ll dist12 = squareDist(p1, p2);     // distance from p1 to p2
   ll dist13 = squareDist(p1, p3);     // distance from p1 to p3
   ll dist14 = squareDist(p1, p4);     // distance from p1 to p4

   //when length of p1-p2 and p1-p3 are same, and square of (p1-p4) = 2*(p1-p2)
   if (dist12 == dist13 && 2*dist12 == dist14) {
      ll dist = squareDist(p2, p4);
      return (dist == squareDist(p3, p4) && dist == dist12);
   }

   //same condition for all other combinations
   if (dist13 == dist14 && 2*dist13 == dist12) {
      ll dist = squareDist(p2, p3);
      return (dist == squareDist(p2, p4) && dist == dist13);
   }

   if (dist12 == dist14 && 2*dist12 == dist13) {
      ll dist = squareDist(p2, p3);
      return (dist == squareDist(p3, p4) && dist == dist12);
  }
  return false;
}

int main(){
    // FILE_READ_OUT
    // FILE_READ_IN
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    V<PLL> arr;
    loop(i,0,n){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        arr.emplace_back(mp(a,b));
        for(int i = 1; i < 4; ++i){
            ll k = arr.rbegin()->F;
            ll l = arr.rbegin()->S;
            k-=c;
            l-=d;
            arr.emplace_back(mp((-1*l)+c,k+d));
        }
    }
    set<PLL> s;
    for(auto i: arr){
        s.insert(i);
    }
    arr.clear();
    for(auto i: s){
        arr.emplace_back(i);
    }
    int ct = 0;
    for(int i = 0; i < arr.size(); ++i){
        for(int j = i+1; j < arr.size(); ++j){
            for(int k = j+1; k < arr.size(); ++k){
                for(int l = k+1; l < arr.size(); ++l){
                    if(isSquare(arr[i],arr[j],arr[k],arr[l])){
                        ct++;
                    }
                }
            }
        }
    }
    cout << ct;
    return 0;
}