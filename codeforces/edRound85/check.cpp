#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse4,avx,avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <chrono>
#include <random>
#include <string>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <sstream>
#include <numeric>
#include <complex>
#include <immintrin.h>
#include <unordered_set>

using namespace std;

using ll = long long;
using ld = long double;
using VectorType = ld;
using ull = unsigned long long;

const ll INF = 1e15;
const ld eps = 1e-7;
const ld pi = atan2(0, -1);
const ll mod = 1e9 + 7;
const ll P = 179, Q = 239;
const ll A = 26;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

ll sign(ll a) {
	if (a < 0) return -1;
	if (a == 0) return 0;
	return 1;
}

bool equal(ld a, ld b) {
	return abs(a - b) < eps;
}

struct query {
	ll l, r, i;

	query(ll l = 0, ll r = 0, ll i = 0) : l(l), r(r), i(i) {};
};

bool mini(ll &a, ll b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

bool maxi(ll &a, ll b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

bool mini(ld &a, ld b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

ll mmax(ll a, ll b) {
	if (a > b) return a;
	return b;
}

ll mmin(ll a, ll b) {
	if (a < b) return a;
	return b;
}

ld mmax(ld a, ld b) {
	if (a > b) return a;
	return b;
}

ld mmin(ld a, ld b) {
	if (a < b) return a;
	return b;
}

bool maxi(ld &a, ld b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

ll sub(ll a, ll b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
	return a;
}

ll add(ll a, ll b) {
	a += b;
	if (a > mod) {
		a -= mod;
	}
	return a;
}

ll mul(ll a, ll b) {
	return (a * b) % mod;
}

ll n, m;
ll k;
vector <vector <ll>> vec;
vector <bool> used;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll l, r;
		cin >> l >> r;
		ll seen = 0;
		ll all = n * (n - 1) + 1;
		ll lastused = 0;
		for (ll i = 1; i <= n; ++i) {
			if (seen + 2 * (n - i) < l) {
				seen += 2 * (n - i);
				lastused = i;
			}
			else {
				break;
			}
		}
//		cout << '\n';
//		cout << "F: ";
//		cout << lastused << ' ' << seen << ' ';
		if (lastused == n) lastused = 0;
		if (l % 2 == 1) {
			// first will be lastused + 1;
			ll toskip = l - seen - 1;
//			cout << toskip << '\n';
//			cout << "Triggered 1\n";
			ll next = lastused + 2 + toskip / 2;
			ll toprint = r - l + 1;
//			cout << "Calculated next as " << next << '\n';
			while (toprint) {
				cout << lastused + 1 << ' ';
				--toprint;
				if (toprint) {
					cout << next << ' ';
					--toprint;
					++next;
					if (next == n + 1) {
//						cout << "( at this point next is " << next << ", resetting.) ";
						++lastused;
						if (lastused == n - 1) lastused = 0;
						next = lastused + 2;
					}
				}
			}
		}
		else {
			// first will be something else;
			ll toskip = l - seen - 1;
//			cout << toskip << '\n';
//			cout << "Triggered 2\n";
			ll first = lastused + 1 + (toskip + 1) / 2;
			ll toprint = r - l + 1;
			while (toprint) {
				cout << first << ' ';
				++first;
				if (first == n + 1) {
					++lastused;
					if (lastused == n - 1) lastused = 0;
					first = lastused + 2;
				}
				--toprint;
				if (toprint) {
					cout << lastused + 1 << ' ';
					--toprint;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
/*
2
3
7 15
2 14
5 3
6
7 15
2 14
5 3
7 15
2 14
5 3
*/