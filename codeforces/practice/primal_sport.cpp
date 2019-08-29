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

const ll maxn = 1e6 + 10;
V<int> primes;
int a;

bool check(int k){
  int j = a-k;
  if(j%2 == 1 || j <= 0){
    return false;
  }
  j/=2;
  int mn = -1;
  for(int i = 0; i < primes.size() && primes[i] <= j; ++i){
    int p1 = primes[i];
    int p2 = j - p1;
    if(binary_search(primes.begin(),primes.end(),p2)){
      if(p1 < k && p2 < (k + p1 + p1)){
        return true;
      }
    }
  }
  return false;
}
int main(){
  int arr[maxn] = {0};
  loop(i,2,maxn){
    if(arr[i] == 0){
      for(int j = 2; i*j < maxn; ++j)arr[i*j]++;
    }
  }
  loop(i,2,maxn){
    if(arr[i] == 0)primes.emplace_back(i);
  }
  int low = 3;
  int high;
  cin >> high;
  a = high;
  int ans ;
  for(int i = 3; i < high; ++i){
    if(check(i)){
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
