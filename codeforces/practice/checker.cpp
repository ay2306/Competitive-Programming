#include <bits/stdc++.h>
using namespace std;
string a, b, s1, s2;
int main()
{
    // freopen("checker.out","w",stdout);
	getline(cin, a);
	getline(cin, b);
	if (a.length() != b.length())
	{
		cout << "-1 -1";
		return 0;
	}
	int n = a.length();
	s1 = a; reverse(s1.begin(),s1.end()); s1 += '\0' + b;
	s2 = b + '\0' + a;
	int *p = new int[2 * n + 1];
	p[0] = 0;
	for (int i = 1; i < 2 * n + 1; ++i)
	{
		p[i] = p[i - 1];
		while (p[i] > 0 && s1[p[i]] != s1[i])
			p[i] = p[p[i] - 1];
		if (s1[p[i]] == s1[i]) 
			++p[i];
	}
	int *z = new int[2 * n + 1];
	z[0] = 0;
	for (int i = 1, l = 0, r = 0; i < 2 * n + 1; ++i)
	{
		z[i] = 0;
		if (i <= r) 
			z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < 2 * n + 1 && s2[z[i]] == s2[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	int ans_i = -1, ans_j = -1;
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] != b[n - i - 1]) break;
		int len = p[2 * n - i - 1];
		if (z[n + i + 2] >= n - i - len - 1)
		{
			ans_i = i;
			ans_j = n - len;
		}
	}
    // for(int i = 1; i <= 2*n; ++i)cout << p[i] << " ";
    // cout << endl;
    // for(int i = 1; i <= 2*n; ++i)cout << z[i] << " ";
    // cout << endl;
	cout << ans_i << ' ' << ans_j << endl;
	return 0;
}