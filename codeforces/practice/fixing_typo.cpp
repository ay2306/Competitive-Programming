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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

int main(){
    string a;
    cin >> a;
    vector<pair<char,int> > arr;
    arr.pb(mp(a[0],1));
    for(int i = 1; i < a.size(); ++i){
        if(a[i-1] == a[i])arr[arr.size()-1].second++;
        else arr.pb(mp(a[i],1));
    }
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i].second > 2)arr[i].second = 2;
    }
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i].second == 2){
            if(i+1 < arr.size() && arr[i+1].second == 2){
                if(i+2 < arr.size() && arr[i+2].second == 2){
                    arr[i+1].second = 1;
                }else{
                    arr[i].second = 1;
                }
                ++i;
            }
        }
    }
    for(auto i: arr){
        for(int j = 0; j < i.second; ++j)cout << i.first;
    }
    return 0;
}