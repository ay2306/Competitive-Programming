#include<iostream>
using namespace std;
bool ifChef(char a, char b, char c, char d){
    int arr[26] = {0};
    arr[a-97]++;
    arr[b-97]++;
    arr[c-97]++;
    arr[d-97]++;
    if(arr[2] && arr[4] && arr[5] && arr[7])return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int cnt = 0;
        for(int i = 0; i+3 < a.length(); ++i){
            if(ifChef(a[i],a[i+1],a[i+2],a[i+3]))cnt++;
        }
        if(cnt)cout << "lovely " << cnt << endl;
        else{cout << "normal\n";} 
    }
}