#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#define ll unsigned long long 
using namespace std;

ll largestPFactor(ll a, vector<ll> list){
     i = 0;
    while(a!= 1){
        if(a%list[i] == 0)a/=list[i];
        else ++i;
    }
    return list[i];
}

vector<ll> sieve(ll lim){
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
    return ans;
}

// ll gcd(ll a, ll b){
//     if(b == 0)return a;
//     return gcd(b,a%b);
// }
// vector<ll> changeVector(vector<ll> vec, ll g,ll i){

// }
 main(){
     t;
    cin >> t;
    while(t--){
        vector<ll> arr,vec;
         n,k;
        cin >> n >> k;
        ll a,g;
        ll max;
        for( i = 0; i < n; ++i){
            cin >> a;
            arr.push_back(a);
            if(i == 0)max = a;
            else{
                if(max < a)max = a;
            }
        }
        bool pos = true;
        vec = sieve(sqrt(max)+1);
        cout << vec.size() << endl;
        cout << ((*(vec.end()-1))*(*(vec.end()-1)))<< endl;
        for( i = 0; i < n; ++i){
            if(largestPFactor(arr[i],vec) > k){
                pos = false;
                break;
            }
        }
        if(pos)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}