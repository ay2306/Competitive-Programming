/*
QUESTION: SUPPOSE YOU ARE GIVE A STRING str[]; AND YOUR ARE ASKED TO ROTATE IT n TIMES SUCH THAT WE GET SAME STRING
FIND MINIMUM VALUE OF n

EXPLANATION: FOR STRINGS LIKE "string" WE HAVE TO ROTATE IT WHOLE TO GET SAME STRING
BUT IF str = "ababababab", WE JUST NEED TO ROTATE IT 2 TIMES TO GET SAME STRING
*/
#include <stdio.h>
#include <string.h>
void rotate(char []);
int calculate(char []);

void rotate(char arr[]){
	int i;
	char tmp = arr[0];
	for(i = 0; arr[i+1]!='\0'; ++i){
		arr[i] = arr[i+1];
	}
	arr[i] = tmp;
}

int calculate(char a[]){
	char b[100];
	int i = 0;
	strcpy(b,a);
	while(1){
		i++;
		rotate(b);
		if(strcmp(a,b)==0){
			break;
		}
	}
return i;
}

int main(){
	int *a = "ababab";
	printf("ANSWER: %d",calculate(a));
	return 0;
}
