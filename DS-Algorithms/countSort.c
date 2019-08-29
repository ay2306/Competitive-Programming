#include<stdio.h>
#include<string.h>
#define RANGE 255
/*void count_sort(char arr[]){
    char output[strlen(arr)];
    int cnt[255+1],i;
    memset(cnt,0,sizeof(arr));
    for(i = 0; arr[i]; ++i)cnt[arr[i]]++;
    for(i = 1; i<=255; ++i){
        cnt[i]+=cnt[i-1];
    }
    for(i = 0; arr[i]; ++i){
        output[cnt[arr[i]]-1] = arr[i];
        --cnt[arr[i]];
    }
    for(i = 0; arr[i]; ++i)arr[i]=output[i];
}
*/
void count_sort(char arr[])
{
    // The output character array that will have sorted arr
    char output[strlen(arr)];

    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // Store count of each character
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];

    // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
int main(){
    char arr[] = "geeksforgeeks";
    count_sort(arr);
    printf("%sn",arr);
return 0;
}
