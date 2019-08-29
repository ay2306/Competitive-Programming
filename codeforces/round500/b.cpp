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
int arr[100100];
int arr1[100100];
int arr2[100100];
int n,x;
bool bSearch(int ind, int val){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == val){
            if(mid != ind)return true;
            if(mid == ind && mid > 0 && arr[mid-1]==val)return true;
            if(mid == ind && mid+1 < n && arr[mid+1]==val)return true;
            return false;
        }
        if(arr[mid] > val)high=mid-1;
        else low = mid+1;
    }
    return false;
}
int main(){
    // FILE_READ
    cin >> n >> x;
    for(int i = 0; i < n; ++i)cin >> arr[i];
    // for(int i = 0; i < n; ++i){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; ++i){
    //     cout << (arr[i]&x) << " ";
    // }
    // cout << endl;
    sort(arr,arr+n);
    for(int i = 1; i < n; ++i){
        if(arr[i] == arr[i-1]){
            cout << "0";
            return 0;
        }
    }
    for(int i = 0; i < n; ++i){
        int val = arr[i]&x;
        if(bSearch(i,val)){
            cout << "1";
            return 0;
        }
    }
    for(int i = 0; i < n; ++i)arr[i] = (arr[i]&x);
    sort(arr,arr+n);
    // for(int i = 0; i < n; ++i)cout << (arr[i]&x) << " ";
    // cout << endl;
    for(int i = 1; i < n; ++i){
        if(arr[i] == arr[i-1]){
            cout << "2";
            return 0;
        }
    }
    cout << "-1";
    return 0;
}