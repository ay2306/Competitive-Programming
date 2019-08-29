#include<bits/stdc++.h>
using namespace std;

int min(int a,int b){
    return (a>b)?b:a;
}

int main(){
    string a;
    int f[10] = {0};
    cin >> a;
    int five = INT_MAX;
    int zero = INT_MAX;
    int two = INT_MAX;
    int seven = INT_MAX;
    int next_zero = INT_MAX;
    int fifty = INT_MAX;
    int twentyfive = INT_MAX;
    int twozero = INT_MAX;
    int seventyfive = INT_MAX;
    for(int i = a.length()-1; i >= 0; --i){
        if(a[i] == '0'){
            if(zero == INT_MAX)zero = i;
            else if(next_zero == INT_MAX)next_zero = i;
        }
        if(a[i] == '5'){
            if(five == INT_MAX)five = i;
            // else if(next_zero == INT_MAX)next_zero = i;
        }if(a[i] == '2'){
            if(two == INT_MAX)two = i;
            // else if(next_zero == INT_MAX)next_zero = i;
        }if(a[i] == '7'){
            if(seven == INT_MAX)seven = i;
            // else if(next_zero == INT_MAX)next_zero = i;
        if(zero != INT_MAX){
        }
            if(next_zero != INT_MAX){
                twozero = ((a.length()-1)-zero)+((a.length()-2)-zero);
            }
            if(five != INT_MAX){
                fifty = ((a.length()-1)-zero)+((a.length()-2)-five);
                if(five > zero){
                    fifty++;
                }
            }
        }
        if(five != INT_MAX){
            if(two != INT_MAX){
                twentyfive = ((a.length()-1)-five)+((a.length()-2)-two);
                if(two > two){
                    twentyfive++;
                }
            }
            if(seven != INT_MAX){
                seventyfive = ((a.length()-1)-five)+((a.length()-2)-seven);
                if(seven > five){
                    seventyfive++;
                }
            }
        }
    }
    if(twentyfive == INT_MAX && seventyfive == INT_MAX && fifty == INT_MAX){
        cout << "-1";
    }
    else{
        int ans = min(seventyfive,min(twentyfive,fifty));
        cout << ans;
    }
    return 0;
}