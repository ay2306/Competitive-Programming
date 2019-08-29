/*
LEXOGRAPHIC ORDER: ALPHABETICAL ORDER
LEXOGRAPHIC MINIMUM: FOR STRING LIKE "GEEKSQUIZ
*/

#include <stdio.h> //COMMON HEADER

int compare(char [], int, int, int);
int min_lex(char [], int);
void print_smallest_sequence(char [], int);

int main(){
	char str[] = "CAPABCQ";
	int n = 0;
	for(; str[n]!='\0';++n);
	print_smallest_sequence(str,n);
return 0;
}

void print_smallest_sequence(char str[],int n){
	int starting_index = min_lex(str,n);
	int i;
	for(i = 0; i < n; ++i){
		printf("%c",str[(starting_index+i)%n]);
	}
}

 int compare(char str[], int a, int b, int n){
	 //printf("%d",n);
	 int i;
	 for(i = 0; i  < n; i++){
		 if(str[a+i]<str[b+i])return 0;
		 if(str[a+i]>str[b+i])return 1;
		 a++;
		 a = a%n;
		 b++;
		 b = b%n;
	 }
	 return 1;
 }
int min_lex(char str[], int n){
	 int index = 0;
	 int i;
	 for(i = 0; i < n; i++){
		 if(compare(str,index,i,n)){
			 index = i;
		 }
	 }
	return index;
}
