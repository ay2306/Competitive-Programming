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
using namespace std;

int find_largest(ull a){
    int i = 0;
    int j = 0;
    while(a){
        if(a%2 == 1)j++;
        a/=2;
        i++;
    }
    return i;
}

bool BS(ull arr[],int n, ull val,bool sp){
    int low = 0;
    int high = n-1;
    while(low <= high){
        // cout << val << endl;
        int mid = low + (high-low)/2;
        // cout << "mid = " << mid << " arr[mid] = " << arr[mid] << " and val = " << val << endl;
        if(arr[mid] == val){
            // cout << "MATCH";
            if(sp){    if(mid < n-1 && arr[mid+1]==val)return true;
                if(mid >= 0 && arr[mid-1]==val)return true;
                return false;
            }else{
                return true;
            }
        }
        if(arr[mid] > val)high = mid - 1;
        else low= mid+1;
    }
    return false;
}

int main(){
    ull n;
    // for(int i = 0; i < 31; ++i){
    //     cout << i << " " << (1 << i) << endl;
    // }
    cin >> n;
    int c = 0,inc = 0;
    ull *arr = new ull[n];
    for(ull i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(ull i = 0; i < n; ++i){
        inc = 0;
        int l = find_largest(arr[i]);
        ull k = (1 << l) - arr[i];
        while(l < 31){
            k = (1 << l) - arr[i];
            // cout << "Searching "<< k << " for " << (1 << l) << " and " << arr[i] << endl;
            if(BS(arr,n,k,k==arr[i])){
                inc = 1;
                break;
            }
            l++;
        }
        if(!inc){
            // ?cout << arr[i] << " ";
            c++;
        }
    }
    // cout << endl <<  c;
    cout << c;
    return 0;
}