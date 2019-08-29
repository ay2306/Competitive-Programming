#include<bits/stdc++.h>
using namespace std;
long long int sum[55];///stores cummulative sum of array

bool isTrue(long long int a,int n,int k)
{
    bool isPart[n+1][k+1];
    memset(isPart,false,sizeof(isPart));
    isPart[0][0]=true;

    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            for(int x=0;x<j;x++)
                isPart[j][i]=isPart[j][i] | (isPart[x][i-1]&&(((sum[j]-sum[x])&a)==a));

    return isPart[n][k];///isPart[n][k] is true of its possible to make a for size n and k parts
}
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    long long int n,k;
    cin>>n>>k;

    long long int arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sum[0]=arr[0];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+arr[i];
    long long int ans=0;///maximum possible answers till now

    long long int a=1;///intialization

    for(int i=61;i>=0;i--)///started from 60 so that numbers tested from highest to lowest because me need maximum answer

            if(isTrue((ans|a<<i),n,k))     /*istrue(x,n,k) function will tell if is it po
                                        possible to divide array of "n" size with "k" parts
                                        such that bitwise and becomes "x" */
            ans=(ans|(a<<i));

    cout<<ans<<endl;

    return 0;
}
