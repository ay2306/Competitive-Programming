#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long doublen
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

string add(string a1, string b1){
    deque<int> s,a,b;
    string ans = "";
    int carry = 0;
    for(int i = 0; i < a1.length(); ++i){
        a.pb(int(a1[i]-'0'));
    }
    for(int i = 0; i < b1.length(); ++i){
        b.pb(int(b1[i]-'0'));
    }
    if(a.size() < b.size()){
        while(a.size()!=b.size()){
            a.push_front(0);
        }
    }
    if(a.size() > b.size()){
        while(a.size()!=b.size()){
            b.push_front(0);
        }
    }
    int i = a.size()-1;
    for(int i = a.size()-1; i >= 0; --i){
        s.push_front((a[i]+b[i]+carry)%10);
        carry = (a[i]+b[i]+carry)/10;
    }
    while(carry){
        s.push_front(carry%10);
        carry/=10;
    }
    for(i = 0; i < s.size(); ++i){
        ans+=(char(s[i]+'0'));
    }
    return ans;
}


int main(){
   int n;
   cin >> n;
   string s;
   cin >> s;
   // cout << add("110","102");
   int mid = n/2;
   string s1,ans3,ans1,ans2;
   while(mid < n && s[mid] == '0')mid++;
   ans1 = add(s.substr(0,mid),s.substr(mid,n-mid));
   mid = n/2+1;
   while(mid >= 0 && s[mid] == '0')mid--;
   ans2 = add(s.substr(0,mid),s.substr(mid,n-mid));
   if(ans1.size() > ans2.size()){
      cout << ans2;
   }else if(ans2.size() > ans1.size()){
      cout << ans1;
   }else{
      if(ans1 > ans2)cout << ans2;
      else cout << ans1;
   }
   return 0;
}