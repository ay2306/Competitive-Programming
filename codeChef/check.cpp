#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifdef LOCAL
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    int n;
    int flag=0;
    long long int seq=0;
    long long int prod=1,k=0;
    int z=1;
    while(t--)
    {
        cin>>n;
        long long int a[n];
        seq=0;
        k=0;
        flag=0;         //position for factor 4
        prod=1;
        z=0;            //store the index if a[i] is zero
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        //calculation for only odd sequences
        for(int i=0;i<n;i++)
        {
           if(a[i]%2!=0)
           {
               seq+=++k;
           }
           else
           {    k=0;
              
           }
        }
        
        //calculation for even 
       for(int i=0;i<n;i++)
       {
           if(a[i]==0)
           {
                prod=1;
                flag=0;
                z=i;
                continue;
           }
           else if(a[i]%4==0)
           {
               if(z==0)
                flag=i+1;
               else
                flag=i-z;
               seq+=flag;
               prod=4;
           }
           else if(a[i]%2!=0 && prod==1)
           {
               flag++;
           }
           else if(a[i]%2==0 && prod<=2)
           {
               prod*=2;
               if(prod==4)
               {
                   flag++;
                   seq+=flag;
               }
           }
           else if(prod==4)
           {
               seq+=flag;
           }
       }
       cout<<seq<<endl;
    }
}