#include<iostream>
#include<limits.h>
using namespace std;

int pop(int stack[], int *top){
    if(*top == -1)return INT_MIN;
    int tmp = stack[*top];
    (*top)--;
    return tmp;
}
void push(int stack[], int *top, int val){
    stack[++(*top)] = val;
}
int main(){
    int n;
    cin >> n;
    int *stack = new int[n];
    int *arr = new int[n];
    int *span = new int[n];
    span[0] = 1;
    for(int i = 0; i < n; ++i)cin >> arr[i];
    int top = -1;
    push(stack,&top,0);
    for(int i = 1; i < n; ++i){
        span[i] = 1;
        while(top!=-1 && arr[stack[top]] < arr[i]){
            span[i]+=span[stack[top]];
            pop(stack,&top);
        }
        push(stack,&top,i);
    }
    for(int i = 0; i < n; ++i)cout << span[i] << " "; cout << endl;
}