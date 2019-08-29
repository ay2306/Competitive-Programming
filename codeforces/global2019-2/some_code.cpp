#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string a;
    cin >> a;
    unsigned int factor = 1;
    unsigned int ans = 0;
    for(int i = a.size()-1; i>= 0; --i){
        ans+=(factor*(a[i]-'A'+1));
        factor*=26;
    }
    cout << ans;
    return 0;
}
