#include<iostream>
#include<vector>
using namespace std;

vector<int> getResult(int n, int r){
    vector<int> vec;
    int m;
    int i = 0;
    if(r == 1){
        for(i = 0; i < n; ++i)vec.push_back(1);
        return vec;
    }
    if(r == 2){
        vec.push_back(2);
        for(i = 1; i < n; ++i)vec.push_back(1);
        return vec;
    }
    if(r == 3){
        if(n%2 == 0){
            vec.push_back(2);
            for(i = 1; i < n; ++i)vec.push_back(1);
            return vec; 
        }
        if(n%2 == 1){
            vec.push_back(3);
            for(i = 1; i < n; ++i)vec.push_back(1);
            return vec; 
        }
    }
    while((1 << i) <= r){
        m = i;
        i++;
    }
    if(n == 1){
        vec.push_back(r);
        return vec;
    }
    if(n == 2){
        vec.push_back((1<<m));
        vec.push_back((1<<m)-1);
        return vec;
    }
    if(n >= 3){
        vec.push_back((1<<m));
        if(n%2 == 1)
        {
            int sum1 = 0;
            for(int i = m/2; i < m; ++i){
                sum1 += (1<<i);
            }
            vec.push_back(sum1);
            int sum2 = 0;
            for(int i = 0; i < m/2; ++i){
                sum2 += (1<<i);
            }
            vec.push_back(sum2);
            int i = 1;
            while(i==sum1 || i==sum2 || i==(1<<m)){i++;}
            for(int k = 3; k < n; ++k){
                vec.push_back(i);
            }
            return vec;
        }
        if(n%2 == 0){
            i = 1;
            vec.push_back((1<<m)-1);
            while(i==((1<<m)-1) || i==(1<<m)){i++;}
            for(int k = 2; k < n; ++k){
                vec.push_back(i);
            }
            return vec;
        }
    }
}

int getXOR(vector<int> vec){
    int ans = vec[0];
    for(int i = 1; i < vec.size(); ++i){
        ans = (ans ^ vec[i]);
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,r;
        cin >> n >> r;
        vector<int> vec = getResult(n,r);
        for(int i = 0; i < vec.size(); ++i){
            cout << vec[i] << " ";
        }
        cout << endl;
        // cout << "XOR = " << getXOR(vec) << endl;
    }
return 0;
}