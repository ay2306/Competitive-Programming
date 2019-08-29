#include<iostream>
#include<sstream>
using namespace std;

void displayLastName(string a){
    if(a[0]>='a' && a[0]<='z')cout << char(a[0]-32);
    else{cout << a[0];}
    for(int i = 1; i < a.length(); ++i){
        if(a[i]>='A' && a[i]<='Z')cout << char(a[i]+32);
        else{cout << a[i];}
    }
}

void func(string str){
    string str1,str2,str3;
    stringstream a(str);
    a >> str1;
    a >> str2;
    a >> str3;
    if(str2==""){
        displayLastName(str1);
        cout << endl;
    }else if(str3 == ""){
        if(str1[0]>='a'&&str1[0]<='z')cout << char(str1[0]-32) << ". ";
        else { cout << str1[0] << ". ";}
        displayLastName(str2);
        cout << endl;
    }else{
        if(str1[0]>='a'&&str1[0]<='z')cout << char(str1[0]-32) << ". ";
        else { cout << str1[0] << ". ";}
        if(str2[0]>='a'&&str2[0]<='z')cout << char(str2[0]-32) << ". ";
        else { cout << str2[0] << ". ";}
        displayLastName(str3);
        cout << endl;
    }
}
int main(){
    int t;   
    string str;
    cin >> t;
    getline(cin, str);
    while(t--){
        getline(cin, str);
        func(str);
    }
}