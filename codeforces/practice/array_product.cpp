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

ll readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
 
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
 
	if (ch == '-') minus = true; else result = ch-'0';
 
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
 
	if (minus)
		return -result;
	else
		return result;
}

bool cmp(PLL a, PLL b){
    return (abs(a.first) >= abs(b.first));
}

int main(){
    int n = readInt();
    V<PLL> pos,neg,zero;
    loop(i,0,n){
        ll a = readInt();
        if(a < 0)neg.pb(make_pair(a,i+1));
        if(a > 0)pos.pb(make_pair(a,i+1));
        if(a == 0)zero.pb(make_pair(a,i+1));
    }
    int pl = 0;
    for(int i = 1; i < pos.size(); ++i){
        cout << "1 " << pos[pl].second << " " << pos[i].second << endl;
        pl = i;
    }
    int nl = 0;
    int zl = 0;
    for(int i = 1; i < zero.size(); ++i){
        cout << "1 " << zero[zl].second << " " << zero[i].second << endl;
        zl = i;
    }
    if(neg.size() % 2 == 0){
        for(int i = 1; i < neg.size(); ++i){
            cout << "1 " << neg[nl].second << " " << neg[i].second << endl;
            nl = i;
        }
        if(zero.size() > 0){
            cout << "2 " << zero[zl].second << endl;
        }
        if(neg.size() && pos.size())cout << "1 " << neg[nl].second << " " << pos[pl].second << endl; 
    }else{
        sort(neg.begin(),neg.end(),cmp);
        for(int i = 1; i+1 < neg.size(); ++i){
            cout << "1 " << neg[nl].second << " " << neg[i].second << endl;
            nl = i;
        }
        cout << "1 " << pos[pl].second << " " << neg[nl].second << endl;
        if(zero.size() > 0){
            cout << "1 " << neg[nl].second << " " << neg[neg.size()-1].second << endl;
            cout << "1 " << neg[nl].second << " " << zero[zl].second << endl;
            nl = neg.size()-1;
        }
        else{
            if(neg.size())cout << "2 " << neg[neg.size()-1].second << endl;
        }
    }
return 0;
}