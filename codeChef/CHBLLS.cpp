#include<iostream>
#include<stdlib.h>
using namespace std;

int getWeight(int a){
    cout << "1" << endl;
    cout << a << " 1 " << endl;
    cout << "0" << endl;
    cout.flush();
    cin >> a;
    return a;
}

int displayAnswer(int a){
    cout << "2\n";
    cout << a << endl;
    cout.flush();
    exit(1);
}

int main(){
    if(getWeight(2) == 1)displayAnswer(2);
    else if(getWeight(3) == 1)displayAnswer(3);
    else if(getWeight(4) == 1)displayAnswer(4);
    else if(getWeight(5) == 1)displayAnswer(5);
    else displayAnswer(1);
    return 0;
}