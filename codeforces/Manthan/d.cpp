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
vector<vector<int> > adj;
vector<int> parent;
vector<int> level;
vector<bool> visited;
int main(){
	int n;
	cin >> n;
	adj = vector<vector<int> > (n,vector<int>());
	parent = vector<int> (n,0);
	visited = vector<bool> (n,false);
	level = vector<int> (n,0);

	for(int i = 1; i < n; ++i){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	queue<int> q;
	vector<int> inp(n);
	loop(i,0,n)cin >> inp[i];
	loop(i,0,n)inp[i]--;
	q.push(inp[0]);
	visited[inp[0]] = true;
	level[inp[0]] = 0;
	while(q.size()){
		int current = q.front();
		q.pop();
		for(auto i: adj[current]){
			if(!visited[i]){
				parent[i] = current;
				level[i] = level[current]+1;
				visited[i] = true;
				q.push(i);
			}
		}
	}
	map<int,int> m;
	for(auto i : adj[inp][0])m[i]++;
	for(int i = 1; i < inp.size(); ++i){
		if(m.find(inp[i]) == m.end()){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}