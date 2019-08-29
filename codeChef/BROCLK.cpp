#include<iostream>
#include<math.h>
#define ll long long int
#define pi 3.14159265
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

ll power(ll x, ll y, ll m){
    if(y == 0)return 1;
    ll p = power(x,y/2,m)%m;
    p = (p * p)%m;
    return (y%2==0)?p:(x*p)%m;
}

ll modinv(ll a, ll m){
    ll ans = 1;
    while(m){
        if(m&1)ans = ((ans%mod)*a)%mod;
        p = p>>1;
        a = (a*a)%mod;
        
    }
    return ans%mod;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ll I,d,t;
        cin >> I >> d >> t;
        double x = acos(float(d)/float(I));
        double timeperround = pi/x;
        timeperround*=2;
        // timeperround/=x;
        double timetocount = t - int(float(t)/timeperround);
        //  cout <<  << endl;
        double y = (I*cos(timetocount*x));
        
    }
    return 0;
}
