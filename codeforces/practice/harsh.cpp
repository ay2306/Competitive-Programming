#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define V vector
#define R return;
#define fast ios_base::sync_with_stdio(false); cin.tie();cout.tie();


const ll mod2=998244353;

ll bpm(ll a,ll b,ll mod)
{
    a%=mod;
    ll res=1;
    while(b)
    {
        if(b%2)
        {
            res=(res*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
        
    }
    return res;
}



ll inv(ll x)
{
    return bpm(x,mod2-2,mod2);
}

V<ll> fact;

ll nCr(ll n,ll r)
{
    ll res=fact[n];
    res=(res*inv(fact[r]))%mod2;
    res=(res*inv(fact[n-r]))%mod2;
    return res;
}

ll calc(ll n,ll k) //calculates stirling(n,k)
{
    ll res=0;
    ll sign=1;
    for(ll i=0;i<=k;i++)
    {
        res=(res+(sign*nCr(k,i)*bpm(k-i,n,mod2))%mod2)%mod2;
    
        sign*=-1LL;
    }
    res=(res*inv(fact[k]))%mod2;
    res=(res+mod2)%mod2;
    return res;
}

void solve(int tc)  //*
//solution using sterling no
//first choose n-k columns 
//now we have to distribute each column to one of the n-k columns such that each column gets at least one row
//now we distribute these n-k distinct sets to n-k distinct columns such that each column gets one set 
{
   ll n,k;
   cin>>n>>k;
   fact=V<ll>(n+1,1);
   for(ll i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod2;
   if(k==0)
   {
       cout<<fact[n];
       R;
   }
   if(k>=n)
   {
       cout<<0;
       R;
   }
   
   ll S=calc(n,n-k);
   ll ans=nCr(n,n-k);
   ans=(ans*S)%mod2;
   ans=(ans*fact[n-k])%mod2;
   ans=(ans*2)%mod2;
   cout<<ans;
}
int main()
{
    fast;
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {solve(t); cout<<"\n";}
    return 0;
}