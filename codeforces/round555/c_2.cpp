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

int main(){
  V<int> arr;
  int n;
  cin >> n;
  loop(i,0,n){
    int a;
    cin >> a;
    arr.pb(a); 
  }
  string ans = "";
  int last = 0;
  int l = 0;
  int r = n-1;
  while(l <= r){
    if(arr[l] > last && arr[r] > last){
      if(arr[l] < arr[r]){
        ans+="L";
        last = arr[l];
        l++;
      }else if(arr[l] > arr[r]){
        ans+="R";
        last = arr[r];
        r--;
      }else{
        int cnt1 = 1;
        int cnt2 = 1;
        int a = l+1;
        int b = r-1;
        while(a <= r){
          if(arr[a] > arr[a-1])cnt1++;
          else break;
          a++;
        }
        while(l <= b){
          if(arr[b] > arr[b+1])cnt2++;
          else break;
          b--;
        }
        if(cnt1 > cnt2){
          last = arr[l];
          l++;
          ans+="L";
        }else{
          last = arr[r];
          r--;
          ans+="R";
        }
      }
    }else if(arr[l] > last){
      ans+="L";
      last = arr[l++];
    }else if(arr[r] > last){
      ans+="R";
      last = arr[r--];
    }else{
      break;
    }
  }
  cout << ans.size() << endl;
  cout << ans;
  return 0;
}
