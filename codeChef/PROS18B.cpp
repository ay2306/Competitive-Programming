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

class Solution{
    V<int> v;
    int q;
    int binary_search_rank(int a){
        int low = 0;
        int high = v.size()-1;
        if(a <= v[0])return -1  ;
        if(a >= v[high])return high;
        while(low <= high){
            int mid = low + high;
            mid/=2;
            if(v[mid] == a)return mid;
            if(mid-1 >= 0 && v[mid-1]<a && v[mid]>a)return mid-1;
            if(mid+1 < v.size() && v[mid+1]>a && v[mid]<a)return mid;
            if(v[mid] < a)low = mid+1;
            else high = mid-1;
        }
    }
public:
    Solution(){
        cin >> q;
        while(q--){
            int a;
            cin >> a;
            if(a == 1){
                int b;
                cin >> b;
                if(v.size() == 0)v.pb(b);
                else{
                    int rank = binary_search_rank(b);
                    v.insert(v.begin()+rank+1,b);
                }
            }else{
                if(v.size()%2 == 0){
                    if(v.size() == 0){
                        printf("0\n");
                    }
                    else{int ans = v[v.size()/2]+v[v.size()/2 - 1];
                    double k = double(ans)/2;
                    printf("%.10f\n",k);}
                }else{
                    double k = v[v.size()/2];
                    printf("%.10f\n",k);
                }
            }
        }
    }
};


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Solution s;
}