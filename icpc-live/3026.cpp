/*____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void solve(string &a){
    int len = a.length();
    vector<int> lps (len);
    lps[0] = 0;
    for(int i = 1, j = 0; i < len; ++i){
        if(a[i] == a[j]){
            lps[i] = j+1;
            j++;
        }else{
            while(true){
                if(j == 0 || a[i] == a[j])break;
                j = lps[j-1];
            }
            if(a[i] == a[j]){
                lps[j] = j+1;
                j++;
            }else{
                lps[i] = 0;
            }
        }
        if(lps[i] == 0)continue;
        int res = i+1-lps[i];
        if((i+1)%res != 0)continue;
        printf("%d %d\n",i+1,(i+1)/res);
    }
}

int main(){
    int t = 1,cas=1;
    string a;
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin >> a;
        printf("Test Case #%d\n",cas++);
        solve(a);
        printf("\n");
    }
    return 0;
}