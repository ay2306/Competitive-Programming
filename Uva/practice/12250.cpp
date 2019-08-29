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
#define MAXN 1001000
using namespace std;
int main(){
    FAST 
    // FILE_READ
    for(int i = 1; i > 0; ++i){
        string a;
        cin >> a;
        if(a == "#")break;
        cout << "Case " << i << ": ";
        if(a.length() > 0){
            if(a[0] == 'H'){
                if(a.length() > 1){
                    if(a[1] == 'E'){
                        if(a == "HELLO")cout << "ENGLISH\n";
                        else{
                            cout << "UNKNOWN\n";
                        }
                    }
                    else if(a[1] == 'O'){
                        if(a == "HOLA")cout << "SPANISH\n";
                        else{
                            cout << "UNKNOWN\n";
                        }
                    }
                    else if(a[1] == 'A'){
                        if(a == "HALLO")cout << "GERMAN\n";
                        else{
                            cout << "UNKNOWN\n";
                        }
                    }else{
                        cout << "UNKNOWN\n";
                    }
                }else{
                    cout << "UNKNOWN\n";
                }
            }
            else if(a[0] == 'B'){
                if(a == "BONJOUR")cout << "FRENCH\n";
                else{
                    cout << "UNKNOWN\n";
                }
            }
            else if(a[0] == 'C'){
                if(a == "CIAO")cout << "ITALIAN\n";
                else{
                    cout << "UNKNOWN\n";
                }
            }
            else if(a[0] == 'Z'){
                if(a == "ZDRAVSTVUJTE")cout << "RUSSIAN\n";
                else{
                    cout << "UNKNOWN\n";
                }
            }else{
                cout << "UNKNOWN\n";
            }
        }
        else{
            cout << "UNKNOWN\n";
        }
    }
    return 0;
}