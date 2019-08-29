#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> pos;
        int n;
        cin >> n;
        int a,k;
        char last = ' ';
        int *arr = new int[n];
        int *ans = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        for(int i = n-1; i >= 0; --i){
            if(last == ' '){
                if(arr[i]>0){
                    k = 1;
                    last = 'p';
                }
                if(arr[i]<0){
                    k = 1;
                    last = 'n';
                }
            }
            else{
                if(arr[i]>0 && last=='n'){k++;last='p';}
                else if(arr[i]<0 && last=='p'){k++;last='n';}
                else if(arr[i]>0 && last=='p'){k = 1;last='p';}
                else if(arr[i]<0 && last=='n'){k = 1;last='n';}
            }
            ans[i] = k;
        }
        for(int i = 0; i < n; ++i)cout << ans[i] << " ";
        cout << endl;
    }
return 0;
}