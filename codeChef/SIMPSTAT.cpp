    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        int t;
        cin >> t;
        while(t--){
            vector<int> vec;
            int n, k, a;
            cin >> n >> k;
            for(int i = 0; i < n; ++i){
                cin >> a;
                vec.push_back(a);
            }
            sort(vec.begin(),vec.end());
            //n = n-(2*k);
            a = 0;
            int s= 0;
            for(int i = k; i < n-k; ++i){
                s+=vec[i];
                a++;
            }
            double y = float(s)/float(a);
            printf("%.7Lf\n",y);
        }
    }