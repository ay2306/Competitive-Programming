    #include<iostream>
    using namespace std;

    int main(){
        int t;
        cin >> t;
        while(t--){
            bool p = true;
            string a;
            cin >> a;
            if(a[0]==a[1])p=false;
            for(int i = 0; i < a.length()-2 && p; i+=2){
                if(a[i]!=a[i+2]){
                    p = false;
                    break;
                }
            }
            if(p)cout << "YES\n";
            if(!p)cout << "NO\n";
        }
    return 0;
    }