#include<iostream>
#include<algorithm>
#include<stdio.h>
#define ll unsigned long long int
#define RANGE 9
using namespace std;

bool validate(ll arr[], ll i, ll n, ll h, ll val, ll sum[]){
    ll k = i;
    ll s = i;
    if((k + (sum[i]/val)) > h)return false;
    i = n-1;
    while(i >= s){
        if(arr[i]%val==0){k = k + (arr[i]/val);}
        else{k = k + (arr[i]/val) + 1;}
        --i;
        if(k > h)return false;
    }
        if(k > h)return false;
        return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n,h;
        cin >> n >> h;
        // scanf("%lld %lld",&n,&h);
        ll *arr = new ll[n];
        ll *sum = new ll[n];
        for(ll i = 0; i < n; ++i){
            cin >> arr[i];
            // scanf("%lld",&arr[i]);
        }
        ll some_really_tmp = n;
        sort(arr,arr+n);
        //radixSort(arr,n);
        n = some_really_tmp;
        for(ll i = n-1; i >= 0; --i){
            if(i == n-1){
                sum[i] = arr[i];
            }else{
                sum[i] = sum[i+1] + arr[i];
            }
            if(i == 0)break;
        }
        ll last = n-2;
        ll start = 0;
        while(start <= last){
            int mid = start + (last - start)/2;
            if(validate(arr,mid+1,n,h,arr[mid],sum)){
                last = mid-1;
            }else{
                start = mid+1;
            }
        }
        start = arr[last];
        ll i = last + 1;
        last = arr[last+1];
        while(start <= last ){
            int mid = start + (last-start)/2;
            if(validate(arr,i,n,h,mid,sum)){
                last = mid-1;
            }else{
                start = mid+1;
            }
        }
        cout << last+1 << endl;
        // printf("%lld\n",(last+1));
    }
}

