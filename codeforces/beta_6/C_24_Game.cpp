#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 3)return cout << "NO",0;
    if(n == 4){
        cout << "YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
        return 0;
    }
    if(n == 5){
        cout << "YES\n";
        cout << "5 - 3 = 2\n";
        cout << "1 + 2 = 3\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24";
        return 0;
    }
    multiset<int> s;
    for(int i = 1; i <= n; ++i)s.insert(i);
    cout << "YES\n";
    if(n%2 == 0){
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        s.erase(1);
        s.erase(2);
        s.erase(3);
        s.erase(4);
        s.insert(24);
        for(int i = 6; i <= n; i+=2){
            cout << i << " - " << i-1 << " = " << 1 << "\n";
            auto it = s.find(i);
            s.erase(it);
            it = s.find(i-1);
            s.erase(it);
            s.insert(1);
        }
        while(s.size() > 1){
            cout << *s.begin() << " * " << *s.rbegin() << " = " << *s.rbegin() << "\n";
            s.erase(s.begin());
        }
        return 0;
    }
    cout << "1 - 2 = -1\n";
    cout << "-1 + 3 = 2\n";
    cout << "2 + 4 = 6\n";
    cout << "6 + 5 = 11\n";
    cout << "11 + 6 = 17\n";
    cout << "17 + 7 = 24\n";
    s.erase(1);
    s.erase(2);
    s.erase(3);
    s.erase(4);
    s.erase(5);
    s.erase(6);
    s.erase(7);
    s.insert(24);
    for(int i = 9; i <= n; i+=2){
        cout << i << " - " << i-1 << " = " << 1 << "\n";
        auto it = s.find(i);
        s.erase(it);
        it = s.find(i-1);
        s.erase(it);
        s.insert(1);
    }
    while(s.size() > 1){
        cout << *s.begin() << " * " << *s.rbegin() << " = " << *s.rbegin() << "\n";
        s.erase(s.begin());
    }
    return 0;
}