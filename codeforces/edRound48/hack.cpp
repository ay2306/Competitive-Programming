#include <bits/stdc++.h>
#define FILE_READ freopen("input.txt","r",stdin);freopen("paout.txt","w",stdout);
using namespace std;
#define ull unsigned long long
#define ll long long
#define nl '\n'
ll n, x, y, z, c1, c2, c3, c4, k, k1, k2, t, a1, a2;
ll pp = (ll)1e10;
ll OO = 0x3f3f3f3f;
string s1, s2;
ll a,c, g;
vector <ll>v;
ll mm = (ll)1e9;
unordered_map<int, int>mp;
int main(){
    FILE_READ
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	ll g = x;
	ll sum = 0;
	for (int i = 0; i < n; i++){
		cin >> z;
		ll cnt = 0;
		mm -= z;
		sum += z;
		if (sum >= x){
			cnt = sum/x;
			sum = sum%x;
		}
		cout << cnt << " ";
	}
	cout << nl;

}