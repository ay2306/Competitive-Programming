// #include<iostream>
// using namespace std;

// struct car{
//     int time;
//     float distance;
//     int wait;
//     int current_tunnel;
//     bool InTunnel;
// }

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         car *Cararr = new car[n];
//         for(int i =0; i < n; ++i){
//             Cararr[i].time = 0;
//             Cararr[i].distance = 0;
//             Cararr[i].wait = 0;
//             Cararr[i].current_tunnel = 0;
//             Cararr[i].InTunnel = true;
//         }
//         int *arr = new int[n];
//         for(int i = 0; i < n; ++i)cin >> arr[i];
//         float c,d,s;
//         cin >> c >> d >> s;
//         float tt = d/s;
//         float aim = (n-1)*d;
//         int current_time = 0;
//         while(Cararr[n-1].distance == aim){
//             current_time++;
//             for(int j = 0; j < c; ++i){
//                 if(Cararr[j].distance == aim)continue;
//                 Cararr[j].time++;
//                 if(Cararr[j].InTunnel){
//                     wait++;
//                     if(wait == tt){
//                         wait = 0;
//                         Cararr[j].InTunnel = false;
//                         Cararr[j].current_tunnel++;
//                         Cararr[j].distance+=s;
//                     }
//                 }
//             }
//         }
//     }
// }

#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int t,n;
        cin >> n;
        int max = 0;
        for(int i = 0; i < n; ++i){
            cin >> t;
            if(max<t)max=t;
        }
        int c,d,s;
        cin >> c >> d >> s;
        //cout << fixed << setprecision(9);
        // if(c==2)cout << max*(c-1) << endl;
        // else{
        //     cout << max*(c-2) << endl;
        // }
        //cout << max*(c-1) << endl;
        float m = max*(c-1);
        printf("%.9f\n",m);
    }   
     return 0;
}