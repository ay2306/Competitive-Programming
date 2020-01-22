// In The Name Of The Queen
#include<bits/stdc++.h>
#define Bit(a, b) ((a) >> (b) & 1LL)
using namespace std;
typedef long long ll;
inline ll Solve(ll l, ll r, ll k)
{
	ll MX = 0, Cnt = 0;
	ll pr = 0, pl = 0;
	bool tr = 1, tl = 1;
	for (int i = 59; ~ i; i --)
	{
		Cnt = (pr >> 1) - (pl >> 1);
		if (tr & Bit(r, i))
			Cnt += (r & ((1LL << i) - 1)) + 1;
		if (tl & Bit(l, i))
			Cnt -= (l & ((1LL << i) - 1)) + 1;
		if (Cnt >= k)
		{
			MX |= 1LL << i;
			pl >>= 1; tl &= Bit(l, i);
			pr >>= 1; tr &= Bit(r, i);
		}
		else
		{
			pl |= (tl & Bit(l, i)) << i;
			pr |= (tr & Bit(r, i)) << i;
		}
	}
	return (MX);
}
int main()
{
	int q;
	scanf("%d", &q);
	for (; q; q --)
	{
		ll l, r, k;
		scanf("%lld%lld%lld", &l, &r, &k);
		printf("%lld\n", Solve(max(l - 1, 0LL), r, k));
	}
	return 0;
}