#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int max1,max2,max1Count,max2Count;
        int n;
        cin >> n;
        int a;
        cin >> a;
        max1 = a;
        cin >> a;
        if(max1<a){
            max2 = max1;
            max1 = a;
            max1Count = 1;
        }else{
            max2 = a;
            max2Count = 1;
        }
        for(int i = 2; i < n; ++i){
            cin >> a;
            if(max1<a){
                max2 = max1;
                max2Count = max1Count;
                max1 = a;
                max1Count = 1;
            }else if(max1 == a){
                max1Count++;
            }else if(max2<a){
                max2 = a;
                max2Count = 1;
            }else if(max2 == a){
                max2Count++;
            }
        }
        double totalPossiblePairs = (n*(n-1))/2;
        double ourPairs = max1Count*max2Count;
        cout << (ourPairs/totalPossiblePairs)<<endl;
       
    }
    
    return 0;
}
