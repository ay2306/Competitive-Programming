#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int


int main() {
    freopen("inp","r",stdin);
    freopen("out1","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin>>n;
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin>>a[i][j];
            }
        }
        int trace=0,r=0,c=0;
        for (int j = 0; j < n; j++) {
            unordered_set<int> row,col;
            for (int k = 0; k < n; k++) {
                if (j==k) {
                    trace+=a[j][k];
                }
                row.insert(a[j][k]);
                col.insert(a[k][j]);
            }
            if (row.size()!=n) {
                r++;
            }
            if (col.size()!=n) {
                c++;
            }
            // row.clear();
            // col.clear();
        }
        cout << "Case #"<<t<<": "<<trace<<" "<<r<<" "<<c << '\n';
    }
  return 0;
}
