#include<iostream>
using namespace std;
const int N = 5e6;
int pr[N],pal[N];
bool pl(int x){
    int s = 0,p=x; 
    while(x){
        s=(s*10)+x%10;
        x/=10;
    }
    return s==p;
}
int main(){
 pal[1] = 1;
 for(int i = 2; i < N; ++i){
     if(pr[i] == 0)for(int j = 2*i; j < N; j+=i){
         pr[j] = 1;
     }
     pal[i] = pal[i-1]+pl(i);
     pr[i]=pr[i-1]+(pr[i]==0);
 }
 double p,q;
 cin >> p >> q;
 p/=q;
 for(int i = N-1; i >= 1; --i){
     if(double(pr[i])<=p*double(pal[i])){
         return cout << i << "\n",0;
     }
 }
 return cout << -1 << "\n",0;
}