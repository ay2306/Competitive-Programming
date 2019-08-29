#include<bits/stdc++.h>
using namespace std;

float getMedian(int f[], int d){
    int j = 0;
    int i;
    // for(int i = 0; i < 201; ++i){
    //     if(f[i])cout << i << " " << f[i] << endl;
    // }
    // cout << "END OF ITERATION\n";
    for(i = 0; i < 201; ++i){
        if(j + f[i] > d/2)break;
        j+=f[i];
    }
    if(d%2 == 1){
        return float(i);
    }else{
        if(j + f[i] > (d/2 + 1)){
            return ((float(i)+float(i+1))/2);
        }else{
           float med = i;
            for(i = 0; i < 201; ++i){
                if(j + f[i] > ((d/2)+1))break;
                j+=f[i];
            }
            med+=i;
            return med/2.0;
        }
    }
}

int main(){
    FILE *fp;
    fp = fopen("fraudData.dat","r");
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    long long int n,d;
    int f[201] = {0};
    // cin >> n >> d;
    fscanf(fp, "%lld%lld",&n,&d);
    int *arr = new int[n];
    for(int i = 0, a; i < d; ++i){
        // cin >> a;
        fscanf(fp,"%d",&a);
        f[a]++;
        arr[i] = a;
    }
    int count = 0;
    for(int i = d, a; i < n; ++i){
      fscanf(fp,"%d",&a);
        // cin >> a;1
        float med = getMedian(f,d);
        arr[i] = a;
        // cout << med << endl;
        f[arr[i-d]]--;
        f[a]++;
        if(a >= 2*med)count++;
    }
    cout << count;
}
