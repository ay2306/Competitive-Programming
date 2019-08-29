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
    FILE_READ
    string a,b;
    int n,m,q;
    cin >> n >> m >> q;
    cin >> a;
    cin >> b;
    int *arr = new int[n];
    arr[0] = 0;
    for(int i = 0; i < n; ++i){
        if(i)arr[i]=arr[i-1];
        if(a[i] == b[0]){
            if(b.length() == 1){
                arr[i]++;
                continue;
            }
            int k = i+1;
            int flag =0;
            for(int j = 1; j < b.length() && k < a.length();++j){
                if(a[k]!=b[j]){
                    break;
                }
                if(j+1 == b.length()){
                    flag = 1;
                }
                ++k;
            }
            if(flag)arr[i]++;
        }
    }
    // for(int i = 0; i < n; ++i){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    while(q--){
        int A,B;
        cin >> A >> B;
        // cout << A << " " << B << " " << endl;
        A--;
        B--;
        if(A+b.length()-1 > B){
            // cout << A+b.length()-1 << " " << B << " ";
            cout << "0\n";
            continue;
        }
        if(A == B){
            if(b.length() == 1 && a[A] == b[0]){
                cout << "1\n";
                continue;
            }else{
                cout << "0\n";
                continue;
            }

        }
        B-=b.length();
        B++;
        if(A == 0){
            cout << arr[B] <<  endl;
        }else{
            // cout << arr[B] << " " << arr[A-1] << " ";
            cout << arr[B]-arr[A-1] << endl;
        }
    }
    return 0;
}