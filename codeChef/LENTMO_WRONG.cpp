#include <bits/stdc++.h>

#define ll long long
using namespace std;



int main() {
	freopen("input.txt","r",stdin);
	freopen("output2.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k, x;
		cin >> n;
		ll arr[n];

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		cin >> k >> x;
		ll vec[n];
		vector<pair<ll, int>>dif(n);
		for (int i = 0; i < n; i++)
		{
			vec[i] = (arr[i] ^ x);
			dif[i].first = vec[i] - arr[i];
			dif[i].second = i;
		}

		int cntpos = 0;

		for (int i = 0; i < n; i++)
			if (dif[i].first > 0)
				cntpos++;

		ll q = cntpos / k;
		ll r = cntpos % k;

		ll ans = 0;

		if (k == 1)
		{
			for (int i = 0; i < n; i++)
			{
				if (dif[i].first > 0)
					ans += vec[i];
				else ans += arr[i];
			}
		}

		else
		{
			if (r % 2 == 0)//if(more.size()%k%2 == 0)
			{
				if ((r == 0) || (q >= 1))
				{
					for (int i = 0; i < n; i++)
					{
						if (dif[i].first > 0)
							ans += vec[i];
						else ans += arr[i];
					}

				}

				else
				{
					if (n >= k + 1)
					{
						for (int i = 0; i < n; i++)
						{
							if (dif[i].first > 0)
								ans += vec[i];
							else ans += arr[i];
						}
					}

					else
					{
						ll ans1 = 0, ans2 = 0;

						for (int i = 0; i < n; i++)
							ans1 += arr[i];
						for (int i = 0; i < n; i++)
							ans2 += vec[i];

						ans = max(ans1, ans2);
					}
					}
			}//(more.size() % k %2 == 0)

			else
			{
				if (q == 0)
				{
					if (n == k)
					{
						ll ans1 = 0, ans2 = 0;

						for (int i = 0; i < n; i++)
							ans1 += arr[i];
						for (int i = 0; i < n; i++)
							ans2 += vec[i];

						ans = max(ans1, ans2);
					}
					else
					{
						if ((k % 2) && (n - cntpos >= k - cntpos + 1))//if(k is odd include all)
						{
							for (int i = 0; i < n; i++)
							{
								if (dif[i].first > 0)
									ans += vec[i];
								else ans += arr[i];
							}
						}

						else
						{
							vector<pair<ll, int>>pos, neg;


							for (int i = 0; i < n; i++)
							{
								if (dif[i].first > 0)
									pos.push_back(dif[i]);
								else neg.push_back(dif[i]);
							}
							sort(pos.begin(), pos.end());
							sort(neg.begin(), neg.end(), greater<pair<ll, int>>());

							for (int i = 1; i < pos.size(); i++)
								ans += vec[pos[i].second];
							for (int i = 1; i < neg.size(); i++)
								ans += arr[neg[i].second];
							if (neg.size())
								ans += max(arr[pos[0].second] + arr[neg[0].second], vec[pos[0].second] + vec[neg[0].second]);
							else ans += arr[pos[0].second];
						}
					}

				}//if(more.size() < k)

				else
				{
					if (k % 2)
					{
						for (int i = 0; i < n; i++)
						{
							if (dif[i].first > 0)
								ans += vec[i];
							else ans += arr[i];
						}
					}

					else
					{
						vector<pair<ll, int>>pos, neg;

						for (int i = 0; i < n; i++)
						{
							if (dif[i].first > 0)
								pos.push_back(dif[i]);
							else neg.push_back(dif[i]);
						}
						sort(pos.begin(), pos.end());
						sort(neg.begin(), neg.end(), greater<pair<ll, int>>());

						for (int i = 1; i < pos.size(); i++)
							ans += vec[pos[i].second];
						for (int i = 1; i < neg.size(); i++)
							ans += arr[neg[i].second];
						if (neg.size())
							ans = max(ans + arr[pos[0].second] + arr[neg[0].second], ans + vec[pos[0].second] + vec[neg[0].second]);
						else ans += arr[pos[0].second];
					}
				}
			}
		}

		cout << ans << '\n';
	}

}
