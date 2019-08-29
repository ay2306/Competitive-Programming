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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;


int root(int arr[], int x){
    while(arr[x] != x){
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}

void UNION(int arr[], int a, int b){
    int p = root(arr,a);
    int q = root(arr,b);
    arr[p] = q;
}

int main(){
    M<int,V<int> > m;
    V<V<int> > t;
    V<int> s;
    int n,o;
    cin >> n >> o;
    int *arr = new int[n+1];
    for(int i = 1; i <= n; ++i)arr[i] = i;
    while(o--){
        int a,b;
        cin >> a >> b;
        UNION(arr,a,b);
    }
    for(int i = 1; i <= n; ++i){
        int p = root(arr,i);
        if(m.count(p) == 0){
            V<int> v;
            v.pb(i);
            m.insert(mp(p,v));
        }else{
            m.find(p)->second.pb(i);
        }
    }
    // for(int i = 0; i < n; ++i){
    //     cout << arr[i+1] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; ++i){
    //     cout << root(arr,i+1) << " ";
    // }
    // cout << endl;
    for(M<int,V<int> >::IT i = m.begin(); i != m.end(); ++i){
        // cout << i->second.size() << endl;
        if(i->second.size() == 1){
            s.pb(i->second[0]);
        }else if(i->second.size() > 3){
            cout << "-1";
            return 0;
        }else{
            t.pb(i->second);
        }
    }
    int two = 0;
    for(int i = 0; i < t.size(); ++i){
        if(t[i].size() == 2)two++;
    }
    if(two > s.size()){
        cout << "-1";
        return 0;
    }
    int j = 0;
    for(int i = 0; i < t.size(); ++i){
        if(t[i].size() == 2){
            t[i].pb(*(s.rbegin()));
            s.pop_back();
        }
    }

    while(s.size()!=0){
        V<int> v;
        v.pb(*(s.rbegin()));
        s.pop_back();
        v.pb(*(s.rbegin()));
        s.pop_back();
        v.pb(*(s.rbegin()));
        s.pop_back();
        t.pb(v);
    }

    for(V<V<int> >::IT i = t.begin(); i != t.end(); ++i){
        for(V<int>::IT j = i->begin(); j != i->end(); ++j){
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}