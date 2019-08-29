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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;

struct node{
  char a;
  node *next;
  node *prev;
};

node *newNode(char a){
  node *ptr = new node;
  ptr->a = a;
  ptr->next = NULL;
  ptr->prev = NULL;
  return ptr;
}

bool insert(node *top, char a){
  node *t = top;
  while(t != NULL){
    if(t->a +1 != a && t->a - 1 != a && (t->next == NULL || (t->next->a +1 != a && t->next->a - 1 != a )))
    {node *ptr = newNode(a);
    ptr->next = t->next;
    ptr->prev = t;
    t->next = ptr;
    if(ptr->next != NULL)ptr->next->prev = ptr;
    return true;}
    t = t->next;
  }
  return false;
}

void solve(){
  string a;
  cin >> a;
  map<char,int> m;
  for(auto &i: a){
    m[i]++;
  }
  if(m.size() == 1){
    cout << a << "\n";
    return;
  }
  stack<char> s;
  node *top = newNode('a'-10);
  insert(top,m.begin()->first);
  insert(top,m.rbegin()->first);
  for(auto &i: m){
    if(i.first == m.rbegin()->first)continue;
    if(i.first == m.begin()->first)continue;
    if(!insert(top,i.first)){
      s.push(i.first);
    }
  }
  while(s.size()){
    if(!insert(top,s.top())){
      cout << "No answer\n";
      return;
    }
    s.pop();
  }
  while(top != NULL){
    loop(i,0,m[top->a]){
      cout << top->a;
    }
    m[top->a] = 0;
    top = top->next;
  }
  cout << "\n";
}
int main(){
  FAST
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
