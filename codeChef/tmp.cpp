#include<bits/stdc++.h>
using namespace std;
template<class TYPE, class COMPARE_TYPE>
class ds{
    vector<TYPE> a;
    function<bool(TYPE,TYPE)> compare;
public:
    ds(){}
    ds(COMPARE_TYPE a){
        compare = a;
    }
    bool compare_last_two(){
        return compare(a.back(),a[a.size()-2]);
    }
    void add(TYPE a){
        this->a.emplace_back(a);
    }
};

int main(){
    function<bool(int,int)> check = [](int a, int b)->bool{
        return a > b;
    };
    ds<int,function<bool(int,int)>> a(check);
    for(int i = 0; i < 50; ++i)a.add(i);
    if(a.compare_last_two())cout << "YES";
    else cout << "NO";
    return 0;
}