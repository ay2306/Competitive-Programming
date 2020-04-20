// C++ program for Pascal’s Triangle 
// A O(n^2) time and O(n^2) extra space  
// method for Pascal's Triangle 
#include <bits/stdc++.h> 
using namespace std; 
  
void printPascal(long long int n) 
{ 
      
    // An auxiliary array to store  
    // generated pscal triangle values 
    long long int arr[n][n];  
  
    // Iterate through every line and  
    // prlong long int integer(s) in it 
    for (long long int line = 0; line < n; line++) 
    { 
        // Every line has number of integers  
        // equal to line number 
        for(int i = 0; i < n-line; ++i)printf("    ");
		for (long long int i = 0; i <= line; i++) 
        { 
        // First and last values in every row are 1 
        if (line == i || i == 0) 
            arr[line][i] = 1; 
        // Other values are sum of values just  
        // above and left of above 
        else
            arr[line][i] = arr[line - 1][i - 1] +  
                            arr[line - 1][i]; 
        
		printf("%4lld    ",arr[line][i]);
		// cout << arr[line][i] << " "; 
        } 
        cout << "\n"; 
    } 
} 
  
// Driver code 
int main() 
{ 
    long long int n = 10; 
    cin >> n;
	printPascal(n); 
    return 0; 
} 
  
// This code is Contributed by Code_Mech. 
