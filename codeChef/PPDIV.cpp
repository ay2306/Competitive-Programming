#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define mod 1000000007
#define ull long long int
#define INV6 166666668
using namespace std;

template<class T>
T cube(T a){
    return a*a*a;
}

template<class T>
T square(T a){
    return a*a;
}

ull f(ull n){
 ull a = n*(n+1);
 if(a >= mod)a%=mod;
 a*=(2*n+1);
 if(a >= mod)a%=mod;
 a*=INV6;
 if(a >= mod)a%=mod;
    return a;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long N;
        vector<long long> processed((int)1e6+100,0),greater_than_cb_less_sq;
        ull i,j,k,ans=0,n;
        scanf("%lld",&N);
        n = N;
        ull cb = cbrt((long double)n);
        ull sq = sqrt((long double)n);
        // We first process all number within cuberoot
        for(i = 2; i <= cb; ++i){
            if(processed[i])continue;
            ull perfect_powers_of_i = i*i;
            while(true){    
                if(perfect_powers_of_i > n)break;
                ull their_value = perfect_powers_of_i;
                ull numbers_they_divide = n/their_value;
                ull sum_they_add = numbers_they_divide*their_value;
                if(sum_they_add >= mod)sum_they_add%=mod;
                // cout << "POWER = " << c(their_value) << " Contribution = " << c(numbers_they_divide*their_value) << "\n";
                ans = (ans + sum_they_add);
                if(ans >= mod)ans-=mod;
                if(their_value <= cb)processed[their_value]=1;;
                if(cb < their_value && their_value <= sq)greater_than_cb_less_sq.emplace_back(their_value);
                if(n/perfect_powers_of_i < i)break;
                perfect_powers_of_i*=i;
            }
        }
        // cout << c(ans) << "\n";
            //  << c(n) << "\n";
        // Now we need to processed majorily all perfect powers except
        // those x^k whose x >= cuberoot. so least number for any such x is x^2
        // now consider x >= cuberoot (it mayalso), n/(x^2) is the count
        // Here things get interesting
        // consider this 
        // (n/x^2), (n/(x+1)^2), (n/(x+2)^2) can be same value as it is integer division
        // therefore
        // (n/x^2)*x^2 + (n/(x+1)^2) + ... = (n/x^2)(x^2 + (x+1)^2 + ...)
        // let n/(START)^2 = A and n/(END)^2 = A
        // now we know for n/(x^2) = 1, x^ at max can be sqrt(n) and at min be sqrt(n/2)-1
        // init_start = sqrt(n/2)+1 and sqrt(n)
        // next_start = sqrt(n/3)+1 and sqrt(n/2)
        // ans basically sqrt(n/(val+1))+1 and sqrt(n/val)
        // val*((start)^2 + (start+1)^2 + ... + (end)^2)
        // consider f(x) = sum of squares of first x natural numbers
        // val*(f(end)-f(start-1));
        // Now x >= cbroot, x^2 = n/A >= n^(2/3)
        // therefore A is at max n^(1/3)

        // cout << "cb = " << c(cb) << "\n";
        for(i = 1; i*i*i <= n; ++i){
            ull start = sqrtl((long double)(n)/(i+1))+1;
            ull end = sqrtl((long double)(n)/i);
            // cout << "start = " << c(start) << " end = " << c(end) << "\n";
            if(start <= cb)start = cb+1;
            if(start > end || end > sq)continue;
            ull f1 = f(end);
            if(start > 0){
                f1-=f(start-1);
                if(f1 < 0)f1+=mod;
            }
            ans = (ans+f1*i);
            if(ans >= mod)ans%=mod;
        }
        // cout << c(ans) << "\n";
        // Now we have included all the squares.
        // But consider N = 1e18 and we went to 1e8 and 1e16 as well
        // they are added twice, so
        // we can just not include them above and let them be here
        // but lets say there was a number which was prime^3 it won't be counted as though it okay but not square
        // so will use saved onces
        for(auto &i: greater_than_cb_less_sq){
            if(i == 0)continue;
            ull data = i*i;
            ull factor = i;
            ull to_del; 
            to_del = (n/data)*data;
            if(to_del >= mod)to_del%=mod;
            ans-=to_del;
            if(ans < to_del)ans+=mod;
        }
        long long out = (ans+n)%mod;
        printf("%lld\n",out);
    }
    return 0;
}