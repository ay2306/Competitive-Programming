#include <stdio.h> // HEADER INCLUDED IN ALL METHODS

//USEFUL COMMON FUNCTION(s)
void output(int arr[],int n){
int i ;
	for(i = 0; i < n; ++i){
		printf("%d  ",arr[i]);
	}
	//printf("\n");
}

/*
METHOD 1: USING TEMPORARY ARRAY
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
*/

/*
void rotate(int arr[], int d, int n){
int k = arr[n-1];
int j = arr[n-1];
int t,i;
int tmp[n];
for(i = 0; i < n; ++i){
	tmp[i]=arr[i];
}
for(i = n-1; i >=0; i--){
	t = i-d;
	if(t<0){
		t = n+t;
	}
	arr[t]=tmp[i];
}
}

int main(){
int array[] = {1,2,3,4,5,6,7};
rotate(array,2,7);
output(array,7);
return 0;
}
*/

/*
METHOD 2: ROTATE ARRAY ONE BY ONE
TIME COMPLEXITY: O(n*d)
SPACE COMPLEXITY: O(1)
*/
/*
void rotatebyOne_left(int[], int);
void rotate(int [], int, int);
int main(){
int array[] = {1,2,3,4,5,6,7};
rotate(array,4,7);
output(array,7);
return 0;
}

void rotate(int a[], int d, int n){
	int i;
	for(i = 0; i < d; i++){
			rotatebyOne_left(a,n);
	}
}

void rotatebyOne_left(int a[], int n){
	int i,tmp;
	tmp = a[0];
	for(i = 0; i < (n-1); i++){
		a[i]= a[i+1];
	}
	a[i]=tmp;
}

*/

/*
METHOD 3: JUGGLING ALGORITHM
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
*/
/*
void rotate(int [], int, int);
int gcd(int, int);
int gcd(int a, int b){
	if(b==0){
		return a;
	}
	else
		return gcd(b,a%b);
}
void rotate(int a[], int d, int n){
	int i,tmp,j,k;
	for(i = 0; i < gcd(n,d); ++i){
		tmp = a[i];
		j=i;
		while(1){
			k = j + d;
			if(k>=n){
				k-=n;
			}
			if(k==i){
				break;
			}
			a[j]=a[k];
			j=k;
		}
	a[j]=tmp;
	output(a,n);
	printf("\n");
	}
}
 int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	rotate(arr,3,12);
	output(arr,12);
	return 0;
 }
 */

 /*
 METHOD 4: REVERSAL ALGORITHM
 TIME COMPLEXITY: O(n)
 */
/*
void rotate(int [], int, int);
void reverse(int [], int, int);
void rotate(int a[], int d, int n){
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
} */
/*
INTEGER NAMING
ll = lower limit
ul = upper limit
*/
/*
void reverse(int a[], int ll, int ul){
	while(ll<ul){
		a[ll] = a[ll]+a[ul];
		a[ul] = a[ll]-a[ul];
		a[ll] = a[ll]-a[ul];
		ll++;
		ul--;
	}
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	rotate(arr,3,12);
	output(arr,12);
	return 0;
 }
 */

 /*METHOD 5: BLOCK-SWAP ALGORITHM
 TIME COMPLEXITY: O(n)
 */
void swap(int [], int, int, int);
void rotate(int [], int, int);

void rotate(int arr[], int d, int n){
	if(d==0 || d==n)return;
	int i,j;
	i = d; j = n-d;
	while(i!=j){
		if(i<j){
			swap(arr,d-i,d+j-i,i);
			j-=i;
		}else{
			swap(arr,d-i,d,j);
			i-=j;
		}
	}
	swap(arr,d-i,d,i);
}
void swap(int arr[], int firstIndex, int lastIndex, int d){
	int i;
	for(i = 0; i < d; ++i){
		arr[firstIndex + i]=arr[firstIndex + i]+arr[lastIndex + i];
		arr[lastIndex + i]=arr[firstIndex + i]-arr[lastIndex + i];
		arr[firstIndex + i]=arr[firstIndex + i]-arr[lastIndex + i];
	}
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	rotate(arr,4,10);
	output(arr,10);
	return 0;
 }
