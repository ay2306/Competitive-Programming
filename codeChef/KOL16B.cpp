#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int z = 0; z < t; ++z){
        int k;
        cin >> k;
        unsigned long long int *arr_a = new unsigned long long int[k];
        unsigned long long int *arr_b = new unsigned long long int[k];
        for(int j = 0; j < k; ++j){
            char b_string[15];
            unsigned long long int a;
            cin >> a;
            unsigned long long int b,c;
            b = 0;
            for(int i = 0; i < 15; ++i){
                if(a%2 == 1)b_string[14-i]='1';
                else if(a%2 == 0)b_string[14-i]='0';
                a = (a>>1);
            }
            a = (a>>1);
            c = a;
            for(int i = 14; i >= 0; --i){
                if(b_string[i] == '1'){
                    int p = 1;
                    for(int m = 0; m < 14-i; ++m)p*=2;
                    b+=p;
                }
            }
            arr_a[j] = b;
            arr_b[j] = c;
        }
        cout << "Case " << (z+1) << ":\n";
        for(int i = 0; i < k; ++i){
            cout << arr_a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < k; ++i){
            cout << arr_b[i] << " ";
        }
        cout << endl;
    }

}