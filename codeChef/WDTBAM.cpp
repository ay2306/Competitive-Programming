#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int cans[26]={0};
        int ans[26]={0};
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        for(int i = 0; i < a.length(); ++i){
            cans[a[i]-65]++;
            ans[b[i]-65]++;
        }
        int c = 0;
        for(int i = 0; i < 26; ++i)c+=((cans[i]>ans[i])?ans[i]:cans[i]);
        int k,o;
        for(int i = 0; i <= n; ++i){
            cin >> k;
            if(i==c)o=k;
        }
        cout << o << endl;
    }
return 0;
}