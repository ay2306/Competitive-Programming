#include<stdio.h>
#include<iostream>
using namespace std;
int n = 110;
double a[n][n],b[n];
void multiply_row(double val, int i){
    for(int j = 0; j < n; ++j){
        a[i][j]*=val;
    }
    b[i]*=val;
}
void add_rows(int i, int j){
    double val = a[i][j]/a[j][j];
    val*=-1;
    for(int col = 0; col < n; ++col){
        a[i][col]+=(val*a[j][col]);
    }
    b[i]+=(val*b[j]);
}
 
void simple_add(int i, int j){
    int k = (i+1)%n;
    while(i != k){
        if(a[k][j] != 0)break;
        k++;
    }
    for(int l = 0; l < n; ++l){
        a[i][l]+=a[k][l];
    }
    b[i]+=b[k];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)printf("%f ",a[i][j]);
        printf("|--| %f\n",b[i]);
    }
}
 
void display(){
    int i,j;
    for(i = 0; i < n; ++i){
        cout <<  b[i]  << " ";
    }
 
}
 
void input(){
    int i,j;
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j)cin >> a[i][j];
        cin >> b[i];
    }
}
 
int main(){
    cin >> n;
    int i,j;
    input();
    for(int i = 0; i < n; ++i){
        if(a[i][i] == 0){
            simple_add(i,i);
        }
        multiply_row(1/a[i][i],i);
        for(int j = 1; j < n; ++j){
            add_rows((i+j)%n,i);   
        }
        // add_rows((i+1)%n,i);
        // add_rows((i+2)%n,i);
    }
    display();
return 0;
}