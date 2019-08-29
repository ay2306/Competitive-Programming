    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        // freopen("input.txt","r",stdin);
        long long int arr[1010];
        int n;
        cin >> n;
        long long int x;
        cin >> x;
        for(int i = 1; i < n; ++i){
            cin >> arr[i];
        }
        sort(arr+1,arr+n,greater<long long int>());
        int i = 1;
        for(i = 1; i < n; ++i){
            if(arr[i] <= x)break;
        }
        if(i <= 10){
            cout << "Happy";
        }else{
            cout << "Not Happy";
        } 
        return 0;
    }