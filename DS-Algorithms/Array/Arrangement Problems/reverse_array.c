/*
QUESTION: WRITE A FUNCTION TO REVERSE AN ARRAY
*/
void reverse(char arr[]){
	int i;
	for(i = 0; arr[i]!='\0';++i);
	int j = i-1;
	i = 0;
	char tmp;
	while(i<j){
		tmp = arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
		i++;
		j--;
	}
	
}
int main(){
	char arr[] = "ayushmahajan";
	reverse(arr);
	printf("%s",arr);
	
}