#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define all(a) a.begin(),a.end()
using namespace std;

int main(){
    int n;
    cin >> n;
    V<string> a(n);
    loop(i,0,n)cin >> a[i];
    sort(all(a),[](string &a,string &b)->bool{
        return (a+b) < (b+a);
    });
    loop(i,0,n)cout << a[i];
   return 0;
}