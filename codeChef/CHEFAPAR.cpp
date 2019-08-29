#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a;
        cin >> n;
        unsigned long long int due = 0;
        while(n--){
            cin >> a;
            if(a == 1){
                if(due!=0){
                    due+=100;
                }
            }else{
                due+=1100;
            }
        }
        cout << due << endl;
    }
}