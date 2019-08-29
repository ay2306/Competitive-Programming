        #include<iostream>
        #include<algorithm>
        #include<vector>
        #define ll long long int
        using namespace std;

        ll maxPeri(vector<ll> vec, int l, int r){
            if(r-l < 2)return 0;
            sort(vec.begin() + l, vec.begin() +(r+1));
            vector<ll>::iterator itr = (vec.begin() + r);
            ll a = *itr;
            --itr;
            ll b = *itr;
            --itr;
            ll c = *itr;
            while(true){
                if(a > (b+c) || a == b || a == c){
                    if(itr == (vec.begin() + l))return 0;
                    --itr;
                    a = *itr;
                }
                else if(b > (a+c)|| a == b || b == c){
                    if(itr == (vec.begin() + l))return 0;
                    --itr;
                    b = *itr;
                }
                else if(c > (b+a)|| c == b || a == c){
                    if(itr == (vec.begin() + l))return 0;
                    --itr;
                    c = *itr;
                }else{
                    return (a+b+c);
                }
            }
        }

        int main(){
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            int n,q;
            cin >> n >> q;
            vector<ll> vec;
            ll a;
            for(int i = 0; i < n; ++i){
                cin >> a;
                vec.push_back(a);
            }
            for(int i = 0; i < q; ++i){
                int rt;
                cin >> rt;
                if(rt == 1){
                    int ind,val;
                    cin >> ind >> val;
                    vec[ind-1] = val;
                }
                if(rt == 2){
                    int l,r;
                    cin >> l >> r;
                    l--;
                    r--;
                    cout << maxPeri(vec,l,r) << endl;
                }
            }
        return 0;
        }