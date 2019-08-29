// #include<bits/stdc++.h>
// #define ll unsigned long long int
// using namespace std;
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         ll mn = INT_MAX;
//         ll a;
//         vector<ll> vec;
//         for(int i = 0; i < n; ++i){
//             cin >> a;
//             vec.push_back(a);
//         }
//         sort(vec.begin(), vec.end());
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int isprime(int n) 
{ 
    if (n <= 1)  return 0; 
    if (n <= 3)  return 1; 
    if (n%2 == 0 || n%3 == 0) return 0; 
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return 0; 
    return 1; 
} 
int semiprime(int num){
    
   int count = 0,inc =0 ;
   for(int i=2;i<=num/2;i++){
       if(num%i==0){
           if(isprime(i)){
           count++;
           }else{inc++;}
       }
   }
   if(count==2 && inc==0){
       return 1;
   }else{
       return 0;
   }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    int t,count,x;
    scanf("%d",&t);
    while(t>0){
        count=0;
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=6;i<n;i++){
            if(semiprime(i)){ 
               arr[count]=i;
               count++;
             }
       }
             
        for(int i=0;i<=count;i++){
            for(int j=i;j<=count;j++){
                if(arr[i]+arr[j]==n){
                    x=1;
                }
            }
        }
        
        if(x==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        x=0;
        t--;
    }

    return 0;
}
