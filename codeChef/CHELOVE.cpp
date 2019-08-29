    #include<iostream>
    #define ll unsigned long long int
    using namespace std;


    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            ll *fin = new ll[n];
            ll *sheath = new ll[n];
            for(int i = 0; i < n; ++i)cin >> fin[i];
            for(int i = 0; i < n; ++i)cin >> sheath[i];
            int front = 1;
            int back = 2;
            for(int i = 0; i < n; ++i){
                if(fin[i] > sheath[i])front = 0;
                if(fin[i] > sheath[n-i-1])back = 0;
            }
            int k = front + back;
            // cout << k << endl;
            switch(k){
                case 0: cout << "none\n"; break;
                case 1: cout << "front\n"; break;
                case 2: cout << "back\n"; break;
                case 3: cout << "both\n"; break;
            }
        }
    }