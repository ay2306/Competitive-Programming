#include<iostream>
#include<vector>
#include<limits.h>
#define ll unsigned long long int
using namespace std;
void build(ll tree[],ll A[], ll node, ll start, ll last){
    if(start == last)tree[node] = A[start];
        else{
        ll mid = (start + last)/2;
        build(tree,A,2*node,start,mid);
        build(tree,A,2*node+1,mid+1,last);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }	
}

void update(ll tree[], ll A[], ll node, ll start, ll last, ll idx, ll val){
    if(start == last){
        A[idx]=val;
        tree[node]=val;
    }
    else{
        ll mid = (start + last)/2;
        if(start <= idx && idx <= mid)update(tree,A,2*node,start,mid,idx,val);
        else{
            update(tree,A,2*node+1,mid+1,last,idx,val);
        }
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

ll query(ll tree[], ll node, ll start, ll last, ll l, ll r){
    if(r<start || last<l)return 0;
    if(l<=start && last<=r)return tree[node];
    ll mid = (start + last)/2;
    ll p1 = query(tree,2*node,start,mid,l,r);
    ll p2 = query(tree,2*node+1,mid+1,last,l,r);
    return (p1+p2);
}


ll closestPrime(vector<pair<ll,bool> > vec, ll num){
    if(num == 0 || num == 1 || num == 2)return 0;
    // ll low = 0;
    // ll high = vec.size()-1;
    // ll mid = low + (high - low)/2;
    // while(low <= high){
    //     mid = low + (high - low)/2;
    //     // cout << "LOW = " << low;
    //     // cout << "\nHIGH = " << high << endl;
    //     if(vec[mid] == num)return vec[mid-1];
    //     if(vec[mid-1]<num && vec[mid]>num)return vec[mid-1];
    //     if(vec[mid+1]>num && vec[mid]<num)return vec[mid];
    //     if(vec[mid]>num)high = mid-1;
    //     if(vec[mid]<num)low = mid+1;
    // return -1;
    num--;
    while(true){
        if(vec[num-2].second)return vec[num-2].first;
        num--;
    }
}
    


vector<pair<ll,bool> > sieve(ll lim){
    vector<pair<ll,bool> > vec;
    vector<ll> ans;
    pair<ll,bool> p;
    for(ll i = 2; i <= lim; ++i){
        p.first = i;
        p.second = true;
        vec.push_back(p);
    }
    for(ll i = 0; i < vec.size(); ++i){
        bool tmp = false;
        if(!vec[i].second)continue;
        for(ll j = vec[i].first*2 - 2; j < vec.size(); j+=vec[i].first){
            if(vec[j].second){
                tmp = true;
                vec[j].second = false;
            }
        }
        if(!tmp)break;
    }
    for(ll i = 0; i < vec.size(); ++i){
        if(vec[i].second){
            ans.push_back(vec[i].first);
        }
    }
    return vec;
}


int main(){
    ll n,q;
    ll max = 0;
    cin >> n >> q;
    ll *a = new ll[n+1];
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
        if(a[i] > max )max = a[i];    
    }
    vector<pair<ll,bool> > vec = sieve(2*max);
    ll f,g,k = n;
    ll *tree = new ll[4*n];
    for(ll i = 1; i < 4*n ; ++i)tree[i]=0;
    build(tree,a,1,1,n);
    while(q--){
        cin >> k;   
        if(k==1){
            cin >> f >> g;
            //     // cout << a[i] << "\t" << closestPrime(vec,a[i]) << endl;
            //     update(tree,a,1,1,n,i,a[i]-closestPrime(vec,a[i]));
            // }
            for(ll i = f; i <= g; ++i){
                a[i] = a[i] - closestPrime(vec,a[i]);
            }
            // cout << "ARRAY = ";
            // for(ll i = 1; i <= n; ++i) cout << a[i] << "\t";
            // cout << endl;
            build(tree,a,1,1,n);
        }
        if(k==2){
            cin >> f >> g;
            cout << query(tree, 1, 1, n, f, g) << "\n";
        }
    }
return 0;
}
