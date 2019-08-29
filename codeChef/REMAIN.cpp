#include<iostream>
#include<vector>
#define ll unsigned long long 
using namespace std;

vector<ll> numbers(string a){
     k = 0;
    ll number = 0;
    for( i = 0; k < 9 && i < a.length() ; ++i ){
        number*=10;
        number+=(a[i]-48);
        ++k;
    }
    vector<ll> result;
    result.push_back(number);
    if(a.length() > 9){
        number = 0;
        k = 0;
        for( i = 9; k < 9 && i < a.length() ; ++i ){
            number*=10;
            number+=(a[i]-48);
            ++k;
        }   
        result.push_back(number);
        number = 1;
        for( i =0 ; i < k; ++i)number*=10;
        result.push_back(number);
    }
return result;
}

 main(){
     t;
    cin >> t;
    while(t--){
         modulus;
        string a;
        cin >> a;
        ll m ;
        cin >> m;
        vector<ll> vec;
        vec = numbers(a);
        if(vec.size() == 3){
            // cout << "Number = " << vec[0] << " x " << vec[2] << " + " << vec[1] << endl; 
            modulus = ((((vec[0]%m)*(vec[3]%m))%m) + (vec[2]%m))%m;
            // cout << modulus << endl;    
        }
        else{
            // cout << vec[0] << endl;
            modulus = vec[0]%m; 
            // cout << endl      
        }
        if(modulus % 2 == 0)cout << "EVEN\n";
        else cout << "ODD\n";

    }
}