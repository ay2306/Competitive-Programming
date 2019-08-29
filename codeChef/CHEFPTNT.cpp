    #include<iostream>
    using namespace std;
    int main(){
        int t;
        cin >> t;
        while(t--){
            int n,m,x,k;
            int evw = 0;
            int odw = 0;
            cin >> n >> m >> x >> k;
            string a;
            cin >> a;
            for(int i = 0; i < a.length(); ++i){
                if(a[i]=='E')evw++;
                else if(a[i]=='O')odw++;
            }
            int totalWork = 0;
            for(int i = 1;  i <= m; ++i){
                if(i%2 == 0){
                    if(evw >= x){
                        evw-=x;
                        totalWork+=x;
                    }else{
                        totalWork+=evw;
                        evw = 0;
                    }
                }
                if(i%2 == 1){
                    if(odw >= x){
                        odw-=x;
                        totalWork+=x;
                    }else{
                        totalWork+=odw;
                        odw = 0;
                    }
                }
            }
            if(totalWork >= n)cout << "yes\n";
            else{cout << "no\n";}
        }
    }