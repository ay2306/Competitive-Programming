#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        bool fol = true;
        string last="";
        string a;
        int n;
        cin >> n;
        {for(int i = 0; i < n; ++i){
            cin >> a;
            if(i==(n-1)){
                //if(a=="milk")cout << "YES\n";
                if(a=="cookie")fol=false;
                continue;
            }
            if(a=="cookie" && (last=="milk" || last=="")){
                last = "cookie";
            }
            else if(a=="cookie" && last=="cookie"){
                fol = false;
            }
            else if(a=="milk"){
                last = "milk";
            }
        }
        if(fol)cout << "YES\n";
        if(!fol)cout << "NO\n";
        }
    }
return 0;
}