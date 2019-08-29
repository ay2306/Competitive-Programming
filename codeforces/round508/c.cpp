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
int main(){
	ll n = readInt();
	ll *A = new ll[n];
	ll *B = new ll[n];
	ll *As = new ll[n];
	ll *Bs = new ll[n];
	for(int i = 0; i < n; ++i)A[i] = readInt();
	for(int i = 0; i < n; ++i)B[i] = readInt();
	As[n-1] = A[n-1];
	Bs[n-1] = B[n-1];
	for(int i = n-2; i >= 0; --i){As[i]=(A[i]+As[i+1]);}
	for(int i = n-2; i >= 0; --i){Bs[i]=(B[i]+Bs[i+1]);}
	int i = 0; int j  = 0;
	ll s1 = 0; ll s2 = 0;
	sort(A,A+n,greater<ll>());
	sort(B,B+n,greater<ll>());
	for(int k = 0; k < 2*n; ++k){
		if(i<n && j < n){
			if(k%2 == 0){
				// cout << "A's turn\n";
				ll cur = s2-s1;
				if((s2+B[j]) >= (s1+A[i]+cur)){
					// cout << "Delete " << B[j] << endl;
					j++;
				}else{
					// cout << "Add " << A[i] << endl;
					s1+=A[i++];
				}	
			}else{
				// cout << "B's turn \n";
				ll cur = s1-s2;
				if((s2+B[j]+cur) <= (s1+A[i])){
					// cout << "Delete " << A[i] << endl;
					i++;
				}else{
					// cout << "Add " << B[j] << endl;
					s2+=B[j++];
				}
			}
		}else if(i >= n){
			if(k%2 == 0){
				// cout << "A's turn \n";
				// cout << "Delete " << B[j] << endl;
				j++;
			}else{
				// cout << "B's turn \n";
				// cout << "Add " << B[j] << endl;
				s2+=B[j++];
			}
		}else{
			if(k%2 == 1){
				// cout << "B's turn \n";
				// cout << "Delete " << A[i] << endl;
				i++;
			}else{
				// cout << "A's turn \n";
				// cout << "Add " << A[i] << endl;
				s1+=A[i++];
			}
		}
	}
	cout << s1-s2;
    return 0;
}