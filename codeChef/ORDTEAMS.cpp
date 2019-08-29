#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d,e,f,g,h,i;
        cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
        bool A = ((a>d && b>=e && c>=f)||(a>=d && b>e && c>=f)||(a>=d && b>=e && c>f));
        bool B = ((a>g && b>=h && c>=i)||(a>=g && b>h && c>=i)||(a>=g && b>=h && c>i));
        bool C = ((a<d && b<=e && c<=f)||(a<=d && b<e && c<=f)||(a<=d && b<=e && c<f));
        bool E = ((a<g && b<=h && c<=i)||(a<=g && b<h && c<=i)||(a<=g && b<=h && c<i));
        bool F = ((g>d && h>=e && i>=f)||(g>=d && h>e && i>=f)||(g>=d && h>=e && i>f));
        bool D = ((d>g && e>=h && f>=i)||(d>=g && e>h && f>=i)||(d>=g && e>=h && f>i));
        if((A && D)||(B && F)||(C && B)||(E && D)||(E && A)||(F && C))cout << "yes\n";
        else{cout << "no\n";}
    }
}