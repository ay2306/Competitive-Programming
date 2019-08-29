#include<bits/stdc++.h>
#define FILE_READ freopen("input.txt","r",stdin);freopen("output2.txt","w",stdout);

using namespace std;
int main()
{
    FILE_READ
    int n,i,j;
    cin>>n;
    i=0;
    j=n-1;
    vector<int>arr(n);
    for(int k=0;k<n;k++)
        cin>>arr[k];
    int sum1=arr[0],sum2=arr[n-1],ans=0;
    cout << "i = " << i << " arr[i] = " << arr[i] <<  " sum1 = " << sum1 << endl;
    cout << "j = " << j << " arr[j] = " << arr[j] <<  " sum2 = " << sum2 << endl;
    i++;
    j--;
    while(i<j)
    {
        if(sum1<sum2)
        {
            sum1+=arr[i];
            i++;
        }
        else if(sum2<sum1)
        {
            sum2+=arr[j];
            j--;
        }
        else
        {
            ans=sum1;
            sum2+=arr[j];
            sum1+=arr[i];
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}