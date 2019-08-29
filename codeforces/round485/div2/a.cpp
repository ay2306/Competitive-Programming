#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<string> vec;
    cin >> n;
    int a[6] = {0};
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        switch(s[0]){
            case 'p': a[0]++; break;
            case 'g': a[1]++; break;
            case 'b': a[2]++; break;
            case 'o': a[3]++; break;
            case 'r': a[4]++; break;
            case 'y': a[5]++; break;
        }
    }
        for(int i = 0; i < 6; ++i){
            if(!a[i]){
                switch(i+1){
                    case 1: vec.push_back("Power"); break;
                    case 2: vec.push_back("Time"); break;
                    case 3: vec.push_back("Space"); break;
                    case 4: vec.push_back("Soul"); break;
                    case 5: vec.push_back("Reality"); break;
                    case 6: vec.push_back("Mind"); break;
                }
            }
        }
        cout << vec.size() << endl;
        for(int i = 0; i < vec.size(); ++i){
            cout << vec[i] << endl;
        }

    return 0;
}