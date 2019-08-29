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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

int bs(int arr[], int n, int k){
    if(k <= arr[0])return -1;
    if(k > arr[n-1])return n-1;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == k){
            if(mid-1 >= 0 && arr[mid-1] < k)return mid-1;
            else high = mid;
        }
        if(arr[mid] > k)high = mid-1;
        else low = mid + 1;
    }
}

int main(){
    FILE_READ
    int n;
    cin >> n;
    int *arr = (int*)calloc(n,sizeof(int));
    int *diff = (int*)calloc(n,sizeof(int));
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        diff[l]++;
        if(r+1 < n)diff[r+1]--;
    }
    arr[0] = diff[0];
    for(int i = 1; i < n; ++i){
        arr[i] = arr[i-1]+diff[i];
    }
    // for(int i = 0; i < n; ++i){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    sort(arr,arr+n);
    // for(int i = 0; i < n; ++i){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    int q;
    cin >> q;
    M<int,int> m;
    m.insert((arr[0],0))
    while(q--){
        int k;
        cin >> k;
        cout << n-1-bs(arr,n,k) << endl;
    }
    return 0;
}