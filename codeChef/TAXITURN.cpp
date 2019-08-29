#include<iostream>
#include<math.h>
using namespace std;
double length(double x1,double y1, double x2, double y2){
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int arr[3][2];
        int n;
        int ct = 0;
        cin >> n;
        cin >> arr[0][0] >> arr[0][1];
        cin >> arr[1][0] >> arr[1][1];
        for(int i = 2; i < n; ++i){
            cin >> arr[2][0] >> arr[2][1];
            //double m1,m2;
            double a = length(double(arr[0][0]),double(arr[0][1]),double(arr[1][0]),double(arr[1][1]));
            double b = length(double(arr[1][0]),double(arr[1][1]),double(arr[2][0]),double(arr[2][1]));
            double c = length(double(arr[2][0]),double(arr[2][1]),double(arr[0][0]),double(arr[0][1]));
            double d = ((a*a)+(b*b)-(c*c));
            // cout << "A = " << a << endl;
            // cout << "B = " << b << endl;
            // cout << "C = " << c << endl;
            d = d/(a*b*2);
            d = acos(d);
            d = M_PI - d;
            // cout << M_PI/2 << endl;
            // cout << d << endl;
            if(d > (M_PI / 4))ct++;
            swap(arr[0][0],arr[1][0]);
            swap(arr[0][0],arr[1][0]);
            swap(arr[1][1],arr[2][1]);
            swap(arr[1][1],arr[2][1]);
        }
        (ct > 0)?cout << "no ": cout << "yes ";
        (ct == 1 || ct == 0)?cout << "yes\n": cout << "no\n";
    }
return 0;
}