#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N =  2e5+10;
int n;
int arr[N],used[N];

int minimum(){
    memset(used,0,sizeof(used));
    loop(i,0,n){
        if(used[arr[i]-1] || used[arr[i]])continue;
        used[arr[i]+1] = 1;
    }
    return accumulate(used,used+N,0);
}

int maximum(){
    memset(used,0,sizeof(used));
    loop(i,0,n){
        if(used[arr[i]-1] == 0){used[arr[i]-1] = 1;continue;}
        if(used[arr[i]] == 0)  {used[arr[i]] = 1;continue;}
        if(used[arr[i]+1] == 0){used[arr[i]+1] = 1;continue;}
    }
    return accumulate(used,used+N,0);
}

int main(){
    cin >> n;
    loop(i,0,n){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    cout << minimum() << " " << maximum();
   return 0;

}