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

class DriveTheCarEasy{
    public:
    DriveTheCarEasy(){
        
    }
    ll calculateDistance(int s, int n, vector<int> speed_changes, vector<int> moments){
        vector<PLL> arr;
        for(int i = 0; i < speed_changes.size(); ++i){
            arr.push_back(mp(moments[i]-1,speed_changes[i]));
        }
        sort(arr.begin(),arr.end());
        ll last_moment = 0;
        ll ans = 0;
        ll lastSpeed = 0;
        ll current_moment;
        ll current_speed;
        for(int i = 0; i < arr.size(); ++i){
            current_moment = arr[i].first;
            current_speed = arr[i].second;
            if(current_moment > s && last_moment < s){
                ans+=((s-last_moment)*lastSpeed);
            }
            else if(current_moment < s){
                ans+=((current_moment-last_moment)*lastSpeed);
            }
            last_moment = arr[i].first;
            lastSpeed += arr[i].second;
        }
        if(last_moment < s){
            ans+=((s-last_moment)*lastSpeed);
        }
        return ans;
    }
};
int main(){
    vector<int> a,b;
    int n,s;
    cin >> s >> n;
    loop(i,0,n){
        int k;
        cin >> k;
        a.pb(k);
    }
    loop(i,0,n){
        int k;
        cin >> k;
        b.pb(k-1);
    }
    DriveTheCarEasy t;
    cout << t.calculateDistance(s,n,a,b) << endl;
    return 0;
}