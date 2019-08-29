# <span style = "font-family: arial">  Documentation </span>
These are the various libraries created so far 

- <span><a href="#TCG">Test Case Generator </a></span>

## <span id="TCG" style = "font-family: arial"> Test Case Generator </span>
Method:

1. getArray <br>
   &nbsp;&nbsp;&nbsp;
   **Usage**: Returns an array (or list) of random numbers of size array_length in which all elements will belong to range element_lower_bound, element_upper_bound<br>
   &nbsp;&nbsp;&nbsp;
   **Parameters**:<br>
    &nbsp;&nbsp;&nbsp; 
    A. *array_length*: Defines the length of that should be returned<br>
    &nbsp;&nbsp;&nbsp; 
    B. *element_lower_bound*: Defines the minimum value any element in the returned array can have<br>
    &nbsp;&nbsp;&nbsp; 
    C. *element_upper_bound*: Defines the maximum value any element in the returned array can have<br>

2. getNumber <br>
   &nbsp;&nbsp;&nbsp;
   **Usage**: Returns a random number which belongs to range element_lower_bound, element_upper_bound<br>
   &nbsp;&nbsp;&nbsp;
   **Parameters**:<br>
    &nbsp;&nbsp;&nbsp; 
    A. *element_lower_bound*: Defines the minimum value that the returned element can have<br>
    &nbsp;&nbsp;&nbsp; 
    B. *element_upper_bound*: Defines the maximum value that the returned element can have<br>

3. writeArray <br>
   &nbsp;&nbsp;&nbsp;
   **Usage**: Writes the passed on array to file, which can be pointed out or by default saved as input.txt in the same path as test.py script <br>
   &nbsp;&nbsp;&nbsp;
   **Parameters**:<br>
    &nbsp;&nbsp;&nbsp; 
    A. *array*: Defines the array that has to be written to the file <br>
    &nbsp;&nbsp;&nbsp; 
    B. *file* (*optional*): Defines the file that is to be written. If not passed, it assumed to be input.txt<br>
    &nbsp;&nbsp;&nbsp; 

4. writeNumber <br>
   &nbsp;&nbsp;&nbsp;
   **Usage**: Writes the passed on number to file, which can be pointed out or by default saved as input.txt in the same path as test.py script <br>
   &nbsp;&nbsp;&nbsp;
   **Parameters**:<br>
    &nbsp;&nbsp;&nbsp; 
    A. *array*: Defines the number that has to be written to the file <br>
    &nbsp;&nbsp;&nbsp; 
    B. *file* (*optional*): Defines the file that is to be written. If not passed, it assumed to be input.txt<br>
    &nbsp;&nbsp;&nbsp; 