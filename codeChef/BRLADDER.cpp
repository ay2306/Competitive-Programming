    #include<iostream>
    using namespace std;
    int main(){
        int q;
        cin >> q;
        while(q--){
            unsigned long long int a,b;
            cin >> a >> b;
            if((a%2)==(b%2)){
                if(a>b){
                    if(a-b == 2)cout << "YES\n";
                    else{cout << "NO\n";}
                }else{
                    if(b-a == 2)cout << "YES\n";
                    else{cout << "NO\n";}
                }
            }else{
                if(a%2==0){
                    if(a>b){
                        if(a-b == 1)cout << "YES\n";
                        else{cout << "NO\n";}
                    }else{cout << "NO\n";}
                }else{
                    if(b>a){
                        if(b-a == 1)cout << "YES\n";
                        else{cout << "NO\n";}
                    }else{cout << "NO\n";}
                }
            }
        }
    return 0;
    }   