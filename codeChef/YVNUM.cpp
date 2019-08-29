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
        #define MAXN 25
        using namespace std;

        long long int modPower(long long int n){
            if(n == 0)return 1;
            if(n == 1)return 10;
            long long int p = modPower(n/2);
            p = ((p%MOD)*(p%MOD))%MOD;
            if(n%2){
                p = ((p%MOD)*(10%MOD))%MOD;
            }
            return p;
        }

        void solve(){
            string n;
            cin >> n;
            long long int ans = 0;
            long long int s = (n.size()*n.size())-1;
            long long int current = 0;
            list<int> a;
            for(auto i: n)a.push_back(i-'0');
            for(int i = 0; i < n.size(); ++i){
                for(auto j: a){
                    ans = (ans%MOD + (j*modPower(s--))%MOD)%MOD;
                }
                int p = *a.begin();
                a.pop_front();
                a.push_back(p);
            }
            cout << ans << endl;
        }

        int main(){
            int t = 1;
            cin >> t;
            while(t--)solve();
            return 0;
        }