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
    struct k{
        int val;
        int left;
        int up;
    };
    void solve(){
        int n;
        cin >> n;
        V<V<k> > arr(n);
        for(int i = 0; i < n; ++i)arr[i] = V<k>(i+1);
        int a;
        cin >> a;
        arr[0][0].val = a;
        arr[0][0].left = a;
        arr[0][0].up = a;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                cin >> a;
                arr[i][j].val = a;
                if(j != i)arr[i][j].up = max(arr[i-1][j].up,arr[i-1][j].left) + a;
                if(j > 0)arr[i][j].left = max(arr[i-1][j-1].up,arr[i-1][j-1].left) + a;
                else arr[i][j].left = arr[i][j].up;
                if(i == j)arr[i][j].up = arr[i][j].left;
            }
        }
        int ans = 0;
        // for(auto i: arr){
        //     for(auto j: i){
        //         printf("(%d,%d,%d) ", j.val,j.left,j.up);
        //     }
        //     printf("\n");
        // }

        for(auto i: arr[n-1]){
            ans = max(i.up,ans);
            ans = max(i.left,ans);
        }
        cout << ans << "\n";
    }

    int main(){
        int t = 1;
        cin >> t;
        while(t--)solve();
        return 0;
    }