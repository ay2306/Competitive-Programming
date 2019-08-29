#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
        while(t--){
            int a[100][100];
            int n,max = 0;
            cin >> n;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    cin >> a[i][j];
                }
            }
            for(int I = 0; I < n; ++I){
                int j = 0;
                int sum = 0;
                for(int i = I ; i < n; ++i){
                    sum+=a[i][j];
                    cout << a[i][j] << "\t";
                    ++j;
                }
                cout << endl;
                if(max < sum)max = sum;
            }
            for(int I = 1; I < n; ++I){
                int j = 0;
                int sum = 0;
                for(int i = I ; i < n; ++i){
                    sum+=a[j][i];
                    // cout << a[j][i] << "\t";
                    ++j;
                }
                // cout << endl;
                if(max < sum)max = sum;
            }
            cout << max << endl;
        }
    return 0;
}
