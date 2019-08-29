#include<bits/stdc++.h>
using namespace std;
int arr[110][100];
int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output1.txt","w",stdout);
    int t;
	cin>>t;
	while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i = 0; i < n; ++i){
            string a;
            cin >> a;
            for(int j = 0; j < m; ++j){
                arr[i][j] = (a[j] == '1');
            }
        }
        // cout << "ORIGINAL\n";
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < m; ++j)cout << arr[i][j];
        //     cout << endl;
        // }
        string s;
        cin>>s;
        for(int b=0;b<s.size();b++)
        {
            int k;
            if(s[b]=='R')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=m-2;j>=0;j--)
                    {
                        if(arr[i][j]==1)
                        {
                            k=j;
                            while(k+1 < m && arr[i][k+1]!=1)
                                k++;
                            arr[i][j]=0;
                            arr[i][k]=1;
                        }

                    }
                }
            }
            else if(s[b]=='L')
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=1;j<m;j++)
                    {
                        if(arr[i][j]==1)
                        {
                            k=j;
                            while(k > 0 && arr[i][k-1]!=1 && k>0)
                                k--;
                            arr[i][j]=0;
                            arr[i][k]=1;
                        }

                    }
                }
            }
            else if(s[b]=='U')
            {
                for(int i=1;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(arr[j][i]==1)
                        {
                            k=j;
                            while(k > 0 && arr[k-1][i]!=1)
                                k--;
                            arr[j][i]=0;
                            arr[k][i]=1;
                        }

                    }
                }
            }
            else
            {
                for(int i=m-1;i>=0;i--)
                {
                    for(int j=n-2;j>=0;j--)
                    {   if(arr[j][i]==1)
                        {
                            k=j;
                            while(arr[k+1][i]!=1 && k<n)
                                k++;
                            if(k == n)k=n-1;
                            arr[j][i]=0;
                            arr[k][i]=1;
                        }
                    }
                }
            }
            // cout << "AFTER " << s[b] << endl;
            // for(int i = 0; i < n; ++i){
            //     for(int j = 0; j < m; ++j)cout << arr[i][j];
            //     cout << endl;
            // }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<arr[i][j];
            cout<<endl;
        }
    }
	return 0;
}
