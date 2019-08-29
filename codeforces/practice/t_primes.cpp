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
#define LIMIT 1000000
using namespace std;

  vector<int> sieve(int limit){
      vector<pair<int,bool> > vec;
      pair<int, bool> p;
      for(int i = 2; i <= limit; ++i){
          p.first = i;
          p.second = true;
          vec.push_back(p);
      }
      int i = 2;
      while(true){
          int itr = false;
          for(int j = (2*i)-2; j <= limit; j+=i){
              if(vec[j].second){
                  vec[j].second = false;
                  itr = true;
              }
          }
          if(!itr)break;
          ++i;
          while(!vec[i-2].second)++i;
      }
      vector<int> res;
      for(int i = 0; i < vec.size(); ++i){
          if(vec[i].second)res.push_back(vec[i].first);
      }
      return res;
  }


int main(){
    ull arr[LIMIT+1] = {0};
    for(ull i = 2; i <= LIMIT; ++i)if(arr[i] == 0)for(ull j = 2; i*j <= LIMIT; ++j)arr[i*j]++;
    int n;
    cin >> n;
    while(n--){
        ull a;
        cin >> a;
        ull q = sqrt(a);
        if(q*q == a && arr[q] == 0 && a!=1)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}