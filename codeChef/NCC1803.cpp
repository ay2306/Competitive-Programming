#include<bits/stdc++.h>
#define ll unsigned long long int
#define mod 1000000007
using namespace std;
vector<ll> SieveOfAtkin(int limit)
{
	vector<ll> vec;
    // 2 and 3 are known to be prime
    vec.push_back(2);
    vec.push_back(3);
    // Initialise the sieve array with false values
    bool sieve[limit];
    for (int i=0; i<limit; i++)
        sieve[i] = false;
 
    /* Mark siev[n] is true if one of the following is true:
     a) n = (4*x*x)+(y*y) has odd number of solutions, i.e., there exist
        odd number of distinct pairs (x, y) that satisfy the equation and
        n % 12 = 1 or n % 12 = 5.
     b) n = (3*x*x)+(y*y) has odd number of solutions and n % 12 = 7
     c) n = (3*x*x)-(y*y) has odd number of solutions, x > y and n % 12 = 11 */
    for (int x = 1; x*x < limit; x++)
    {
        for (int y = 1; y*y < limit; y++)
        {
            // Main part of Sieve of Atkin
            int n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
 
            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;
 
            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
 
    // Mark all multiples of squares as non-prime
    for (int r = 5; r*r < limit; r++)	
    {
        if (sieve[r])
        {
            for (int i = r*r; i < limit; i += r*r)
                sieve[i] = false;
         }
    }
 
    // Print primes using sieve[]
    for (int a = 5; a < limit; a++)
        if (sieve[a])
           vec.push_back(a);
return vec;
}

bool isprime(vector<ll> list, int target){
	if(find(list.begin(),list.end(),target)!=list.end())return true;
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	// int z = 1;
	vector<ll> primes = SieveOfAtkin(1000000);
	// for(vector<ll>::iterator itr = primes.begin(); itr!=primes.end(); ++itr){
	// 	cout << *itr << "  ";
	// 	if(z == 5){
	// 		cout << endl;
	// 		z= 0;
	// 	}
	// 	z++;
	// }
	cin >> t;
	while(t--){
		int n,a;
		cin >> n;
		int cnt=0;
		vector<ll> numv;
		queue<ll> per;
		for(int i = 0; i < n; ++i){
			cin >> a;
			if(binary_search(primes.begin(),primes.end(),a)){
				vector<ll>::iterator itr = find(numv.begin(),numv.end(),a);
				if(itr == numv.end())numv.push_back(a);
				else{
					*itr = -1;
					cnt++;
				}
			}
			ll p = sqrt(a);
			if(p*p == a){
				if(binary_search(primes.begin(),primes.end(), p)){
					vector<ll>::iterator itr = find(numv.begin(),numv.end(),1);
					if(itr == numv.end())per.push(a);
					else{
						*itr = -1;
						cnt++;
					}
				}
			}
			if(a == 1){
				if(per.size()!=0){
					cnt++;
					per.pop();
				}else{
					numv.push_back(1);
				}
			}
		}
		if(cnt%2==0)cout << "Shivam\n";
		if(cnt%2==1)cout << "Sagar\n";
	}
return 0;
}


