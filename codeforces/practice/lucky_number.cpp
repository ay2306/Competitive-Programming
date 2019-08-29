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
V<ull> lucky;
V<ull> vec;
void generateLucky(){
    lucky.pb(4);
    lucky.pb(7);
    for(int i = 2; i <= 10; ++i){
        V<ull> tmp = lucky;
        for(int j = 0; j < lucky.size(); ++j){
            tmp.pb((lucky[j]*10)+4);
        }
        for(int j = 0; j < lucky.size(); ++j){
            tmp.pb(lucky[j]);
        }
        for(int j = 0; j < lucky.size(); ++j){
            tmp.pb((lucky[j]*10)+7);
        }
        lucky = tmp;
    }
}

void generate_super_lucky(){
    for(int i = 0; i < lucky.size(); ++i){
        ull a = lucky[i];
        // cout << a << "  ";
        int f=0,s=0;
        while(a){
            if(a%10 == 4)f++;
            if(a%10 == 7)s++;
            a/=10;
        }
        // cout << " f: " << f << "  s: " << s << endl;
        if(s == f)vec.pb(lucky[i]);
    }
}

ull next(ull val, V<ull> v=vec){
    ull low = 0;
    ull high = v.size()-1;
    ull mid;
    if(v[0] >= val)return v[0];
    if(v[v.size()-1] <= val)return *(v.rbegin());
    while(low < high){
        mid = low + (high-low)/2;
        if(v[mid] == val){
            return val;
        }
        if(v[mid-1] < val && v[mid] > val)return v[mid];
        if(v[mid+1] > val && v[mid] < val)return v[mid+1];
        if(v[mid] > val)high=mid-1;
        else low = mid+1;
    }
}


int main(){
    generateLucky();
    generate_super_lucky();
    sort(vec.begin(),vec.end());
    ull a;
    cin >> a;
    // cout << vec.size() << endl;
    cout << next(a);
    return 0;
}