#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}


int main()
{
	int x;
	int n;
	cin>>x>>n;
	string a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int c=0;
	int count=0;
	for( int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
		{
			c=0;
			for(int y=0;y<4;y++)
			{
				int seat;
				seat=j*4+y;
				if(a[i][seat]=='0')
				c++;
			}
			for(int y=1;y<3;y++)
			{
				int s;
				s=(9-j)*2-y+36;
				if(a[i][s]=='0')
				c++;
			}
			//cout<<c<<" "<<i<<" "<<j<<endl;
			if(c!=0)
			count=count+nCr(c,x);
		}
	}
	cout<<count;
}