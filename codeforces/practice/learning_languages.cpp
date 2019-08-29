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

int root(int arr[], int x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
        x = arr[x];        
    }
    return x;
}
void UNION(int arr[], int x, int y){
    int px = root(arr,x);
    int py = root(arr,y);
    arr[px] = py;
}


int main(){
    int n,m;
    int c = 0;
    int ns = 0;
    cin >> n  >> m;
    int *arr = new int[m];
    int *sp = new int[m];
    int *ans = new int[m];
    for(int i = 0; i < m; ++i){
        arr[i] = i;
        sp[i] = 0;
        ans[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        int k;
        // cout << "Enter number of languages spoken: \n";
        cin >> k;
        int a,b;
        if(k == 0)ns++;
        else{
            cin >> a;
            a--;
            sp[a]++;
            for(int j = 1; j < k; ++j){
                // cout << "Enter " << j << "th language: \n";
                cin >> b;
                b--;
                sp[b]++;
                UNION(arr,a,b);
                a=b;
            }
        }
    }
    for(int i = 0; i < m; ++i){
        ans[root(arr,i)]++;
    }
    for(int i = 0; i < m; ++i){
        // cout << i << " " << sp[i] << endl;
        if(ans[i] > 0 && sp[i] > 0){
            c++;
            // cout << i << endl;
        }
    }
    if(c>0)c--;
    cout << ns+c;
    return 0;
}