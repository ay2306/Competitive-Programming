    #include<iostream>
    using namespace std;
    int main(){
        int t;
        cin >> t;
        while(t--){
            int arr[7] = {0};
            int n;
            bool ans = true;
            cin >> n;
            int *a = new int[n];
            for(int i = 0; i < n; ++i){
                cin >> a[i];
                arr[a[i]-1]++;
                if(a[i]<1 || a[i]>7)ans=false;
            }
            for(int i = 0; i < 7; ++i){
                if(arr[i]==0){
                    ans=false;
                    break;
                }
            }
            //if(n%2==0)ans=false;
            if(ans){
                if(a[0] != a[n-1])ans=false;
                else{
                    if(a[0]==1){
                        int i = 1;
                        int j = n-2;
                        while(i<=j){
                            if((a[i]==a[i-1])||(a[i]==a[i-1]+1)){
                                if(a[i]!=a[j]){
                                    ans=false;
                                    break;
                                }
                                i++;
                                j--;
                            }else{
                                ans = false;
                                break;
                            }
                        }
                    }else{
                        ans = false;
                    }
                }
            }
            if(ans)cout << "yes\n";
            if(!ans)cout << "no\n"; 
        }
        return 0;
    }