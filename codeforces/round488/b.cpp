#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
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


int main(){
    FAST
    ll a,b;
    int n,k;
    M<ll,ll> m;
    V<ll> tt;
    cin >> n >> k;
    V<P<ll,ll> > p;
    for(int i = 0; i < n; ++i){
        cin >> a ;
        p.pb(mp(a,1));
        tt.pb(a);
    }
    for(int i = 0; i < n; ++i){
        cin >> a ;
        p[i].second = a;
    }
    sort(p.begin(),p.end());
    priority_queue<ll, V<ll>, greater<ll> > pq;
    
    ll sum = 0;
    for(int i = 0; i <= k && i < n; ++i){
        sum+=p[i].second;
        m.insert(mp(p[i].first,sum));
        pq.push(p[i].second);
    }
    for(int i = k+1; i < n; ++i){
        ll tmp = pq.top();
        if(tmp < p[i].second){
            pq.pop();
            pq.push(p[i].second);
            sum+=p[i].second;
            sum-=tmp;
            m.insert(mp(p[i].first,sum));
        }
        else{
            ll tmpSum = sum;
            tmpSum-=pq.top();
            tmpSum+=p[i].second;
            m.insert(mp(p[i].first,tmpSum));
        }
    }
    for(int i = 0; i < n; ++i){
        cout << m.find(tt[i])->second << " ";
    }

    return 0;
}