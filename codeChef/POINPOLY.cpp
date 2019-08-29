#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b,a;
        vector<int> x,y,rx,ry;
        vector<double> m;
        int j = 0;
        for(int i = 0; i < n; ++i){
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
            if(i>0){
                double o = float(x[i]-x[i-1])/float(y[i]-y[i-1]);
                m.push_back(o);
            }
            if(i>=n/2){
                rx.push_back((x[i]+x[j])/2);
                ry.push_back((y[i]+y[j])/2);
                j++;
            }
        }
        bool line = false;
        for(int i = 1; i < m.size(); ++i){
            if(m[i]!=m[i-1]){
                line = false;
                break;
            }
        }
        for(int i = 0; i < n/10 && !line; ++i){
            cout << rx[i] << " " << ry[i] << endl;
        }
        if(line)cout << "-1\n";
    }
    return 0;
}