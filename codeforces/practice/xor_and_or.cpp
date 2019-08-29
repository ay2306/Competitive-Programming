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
    string a,b;
    cin >> a >> b;
    if(a.length() != b.length()){
        cout << "NO";
        return 0;
    }
    map<char,int> m1;
    map<char,int> m2;
    if(a==b){
        cout << "YES";
        return 0;
    }
    for(auto i: a)m1[i]++;
    for(auto i: b)m2[i]++;
    if(m1['1'] == m2['1'] && m1['0'] == m2['0']){
        if(m1['1']!= 0 && m1['0']!=0){
            cout << "YES";
            return 0;
        }else{
            cout << "NO";
            return 0;
        }
    }
    if(m1['0'] == a.length() || m2['0'] == a.length()){
        cout << "NO";
        return 0;
    }else{
        cout << "YES";
        return 0;
    }
    return 0;
}