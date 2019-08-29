#include <iostream>
using namespace std;
        
long long int Merge(int v[], int l,int r){
    long long int res=0;
    int mid=(l+r)/2, i=l,j=mid+1,k=0;
    int b[ r-l+1 ];
    while( i<=mid && j<=r ){
        if(v[i]<=v[j]){
            b[k]=v[i];
            i++;
            }
        else{
            res+=mid-i+1;
            b[k]=v[j];
            j++;
        }
        k++;
    }   
    
    while(i<=mid){
        b[k]=v[i];
        i++; k++;
    }
    while(j<=r){
        b[k]=v[j];
        j++; k++;
    } 
    for(i=0;i<r-l+1;i++){
        v[l+i]=b[i];
    }
    return res;
}
    
long long rollct(int v[],int l,int r){
    if(r<=l)return 0;
    int mid=(l+r)/2;
    long long  res=rollct(v,l,mid);
    res+=rollct(v,mid+1,r);
    res+=Merge(v,l,r);
    return res;
}
    
int main(int argv, char** args)
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cout<< rollct(a,0,n-1) ;
    return 0;
}