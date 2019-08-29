#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        // reverse(all(a));
        // reverse(all(b));
        string sum = "";
        int carry = 0;
        for(int i = 0; i < max(a.size(),b.size()); ++i){
            int s = carry;
            if(i < a.size())s+=(a[i]-'0');
            if(i < b.size())s+=(b[i]-'0');
            carry = s/10;
            s=s%10;
            sum+=(char(s+'0'));
        }
        if(carry)sum+=(char(carry+'0'));
        int i = 0;
        while(i < sum.size() && sum[i] == '0')i++;
        while(i < sum.size())cout << sum[i++];
        cout << "\n";
    }
   return 0;
}