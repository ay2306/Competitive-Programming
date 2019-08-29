/*
QUESTION: YOU ARE GIVEN AN ARRAY arr. FIND OUT OF ROATIONS WHICH ONE ARE DIVISIBILE BY FOUR
*/

int divisibleByFour(char a[]){
	int i;
	for(i = 0; a[i]!='\0'; ++i);
	--i;
	if((a[i]=='2' || a[i]=='6')&&(a[i-1]=='1' || a[i-1]=='3'||a[i-1]=='5' || a[i-1]=='7'||a[i-1]=='9'))return 1;
	if((a[i]=='0' || a[i]=='4' || a[i]=='8')&&(a[i-1]=='2' || a[i-1]=='4'||a[i-1]=='6' || a[i-1]=='8'|| a[i-1]=='0'))return 1;
	return 0;
}

void rotate(char a[]){
	char b = a[0];
	int i = 0;
	for(; a[i+1] != '\0'; ++i){
		a[i] = a[i+1];
	}
	a[i] = b;
}

int main(){
int i =0;
int j = 0;
char a[] = "20";
if(divisibleByFour(a))j++;
	for(i = 0; a[i+1]!='\0'; i++){
		rotate(a);
		if(divisibleByFour(a))j++;
	}
printf("%d",j);
return 0;
}
