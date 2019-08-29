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

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    V<int> cap,small,dig;
    for(int i = 0 ; i < s.length(); ++i){
        if(s[i] >= 'a' && s[i] <= 'z')small.pb(i);
        if(s[i] >= 'A' && s[i] <= 'Z')cap.pb(i);
        if(s[i] >= '0' && s[i] <= '9')dig.pb(i);
    }
    if(small.size() && cap.size() && dig.size()){
        cout << s << endl;
        return;
    }
    if(small.size() && !cap.size() && !dig.size()){
        s[0]=(s[0]-'a'+'A');
        s[1]=((s[1]-'a')%9+'1');
        cout << s << endl;
        return;
    }
    if(!small.size() && cap.size() && !dig.size()){
        s[0]=(s[0]+'a'-'A');
        s[1]=((s[1]-'A')%9+'1');
        cout << s << endl;
        return;
    }
    if(!small.size() && !cap.size() && dig.size()){
        s[0]=(s[0]-'0'+'A');
        s[1]=(s[1]-'0'+'a');
        cout << s << endl;
        return;
    }
    if(!small.size()){
        if(cap.size() < dig.size()){
            for(int i = 0; i < n; ++i){
                if(s[i]>='0' && s[i]<='9'){
                    s[i] = s[i]-'0'+'a';
                    break;
                }
            }
        }else{
            for(int i = 0; i < n; ++i){
                if(s[i]>='A' && s[i]<='Z'){
                    s[i] = s[i]-'A'+'a';
                    break;
                }
            }

        }
        cout << s << endl;
        return ;
    }
    if(!cap.size()){
        if(small.size() < dig.size()){
            for(int i = 0; i < n; ++i){
                if(s[i]>='0' && s[i]<='9'){
                    s[i] = s[i]-'0'+'A';
                    break;
                }
            }
        }else{
            for(int i = 0; i < n; ++i){
                if(s[i]>='a' && s[i]<='z'){
                    s[i] = s[i]-'a'+'A';
                    break;
                }
            }

        }
        cout << s << endl;
        return ;
    }
    if(!dig.size()){
        if(cap.size() < small.size()){
            for(int i = 0; i < n; ++i){
                if(s[i]>='a' && s[i]<='z'){
                    s[i] = (s[i]-'a')%9+'1';
                    break;
                }
            }
        }else{
            for(int i = 0; i < n; ++i){
                if(s[i]>='A' && s[i]<='Z'){
                    s[i] = (s[i]-'A')%9+'1';
                    break;
                }
            }

        }
        cout << s << endl;
        return ;
    }
}

int main(){
    int t ;
    cin >> t;
    while(t--)solve();
    return 0;
}