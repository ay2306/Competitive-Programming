#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output_checker.txt","w",stdout);
using namespace std;

int main(){
    // FAST
    FILE_READ
    int n;
    cin >> n;
    int *arr = (int*)calloc(n,sizeof(int));
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int l,r;
        cin >> l >> r;
        l--; r--;
        while(l<n && l <= r){
            arr[l]++;
            ++l;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        int c = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] >= k){
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}