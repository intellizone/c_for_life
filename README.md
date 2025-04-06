# c_for_life

## datatypes:
1. int
2. short
3. float
4. char
5. double
6. void
7. struct

void is actually not a data type \
struct helps us creating our own datatype

1. bool:
- 1 byte

2. char
- %c
- 8 bit or 1 byte

3. short
- %hi
- 16 bits or 2 byte

4. int:
- %i
- 32 bit or 4 byte

5. long:
- %ld
- 64 bit or 8 byte

6. float
- %f
- 32 bit or 4 byte

7. double
- %lf
- 64 bit or 8 byte 

8. string:
- %s
- size always varies

## variable declaration
```c
// dataType variableName = value;
int a;
int b=1;   // initialization
int a,b,c; // declaration 
a = 1;     // assignment 
int a=1,b=2;

char a='c';

float a;
a=1.1;
```

## operators
* = --> assignment operator
- Arithmetic operators
    * \+  --> addition operator
    * \-  --> subract
    * \*  --> Multiplicator
    * /  --> division
    * %  --> modules operator (gives reminder)
    * +=   --> ie. a = a + x
    * ++   --> increment by 1
    * --   --> decrement by 1
- Boolean operators:
    - Logical operators:
        * &&  --> Logical AND
        * ||  --> Logical OR
        * | --> bitwise OR
        * & --> bitwise AND
        * ! --> NOT operator
    - Relational Operators:
        * ==
        * != 
        * \>
        * <
        * \>=
        * <=

    Note all non zero value is *true*

## Conditional Statements
* if
* else if
* else

```c
if (boolean-expression){

}
else if (boolean-expression){

}
else{

}

// else will bind to the nearest if
```
* switch - case
```c
switch(x){
    case 1:
    break; /* without break it will run everything after the condition gets 
              first condition gets satisfiled 'falls through' */
    case 2:
    break;
    default:
}
```
* ternary operators [?:]
```c
// int x = (expression)? for_true : for_false
printf("%i", (a>b)?a:b);



// Sample code
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a = get_int("a: ");
    int b = get_int("b: ");
    printf("%i is bigger among %i and %i\n",(a>b) ? a : b, a, b );
}
```
## loops
* for 
```c
for ( int i=10 /* initialization */ ; i > 0 /* logics */ ; i-- /*some operations */){

}
```
* while
```c
int i = 10; // initialization
while (i>0) // logics
{
    i--;    // operations
}
```
* do while - loop should run atleast once
```c
do{

}while(expr)
```

### infinite loop
```c
while 1{
    // runs forever untill ctrl+c is hit
}
```
## Magic Numbers
- hard-coded value in your code
- C has a *preprocessor directive* so called *macors*
```c
#define NAME REPLACEMENT
#define WORD_LENGTH 8
#define NAME "Intellizone"
```
## cryptography 
- ceaser's cipher

## Array:
```c
// type variable_name[size];
int arr[size_of_array];
int arr[]={1, 2, 3, 4}
```

- array starts from position 0
- string always ends with \\0[nul]

## Command-line arguments[CLI]
```c
int main(int argc, string argv[]);

// argc --> argument count
// argv --> argument vector
```
```bash
# usage
./main "someText"
```

## strings in c
```c
#include <string.h>

int strlen(char *string);
```

## character operations in c
```c
#include <ctype.h>
```

## exit code
> mostly exit code **0** indicates success \
> Non 0 indicates something \
> -ve values says errors or  failures.

## functions
- subroutines 
- procedures
- methods
- blackbox

### why functions?
- organization
- simplification - easy to debug
- reusability 

all meaning the same

input --> functions --> outputs

```c
// return_value_type function_name(argument_type argument_variable/value,.....);
int mul(int a, int b);
```

> no return value use "void"
```c
void main(void)
// no input no output
```

## type-casting
```c
// (int) 3.0


#include <stdio.h>

int main(void){
    printf("%i\n",(int) 3.0);
}
```
## variable scope
- local
- global

## Algorithms:
### Big O notaion (O) - Worst case senario:
- O($n^2$)
- O(nlogn)
- O(n)      - Linear search
- O(logn) - Binary search
- O(1)
### Big omega - Best case senario - ($\Omega$)
- $\Omega$($n^2$)
- $\Omega$(nlogn)
- $\Omega$(n)
- $\Omega$(logn)
- $\Omega$(1) - Linear search, binary search

### Teta notation - When big O and big omega are same
- $\theta$($n^2$)
- $\theta$(nlogn)
- $\theta$(n)
- $\theta$(logn)
- $\theta$(1)


## Linear search
- Search one by one

```c
#include <cs50.h>
#include <stdio.h>

int linear_search(int arr[], int l, int k);

int main(void)
{
    int arr_len = 7;
    int arr[] = {200, 10, 5, 70, 95, 86, 80};
    int key = get_int("Enter search number: ");

    if (linear_search(arr, arr_len, key) == 0)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
}

int linear_search(int arr[], int l, int k)
{
    for (int i = 0; i < l; i++)
    {
        if (arr[i] == k)
        {
            return 0;
        }
    }
    return 1;
}

```

## Data Structures:
```c
typedef struct
{
    // data_type variable_name;
    string name;
    string number;
} person;

person persons;
persons.name = "John";
persons.number = "+11-111-111";
```

```c
// Linear search with string

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string location;
} person;

int linear_search(person arr[], int l, string k);

int main(void)
{
    int arr_len = 3;
    person people[arr_len];
    people[0].name = "Suriya";
    people[0].location = "Pune";

    people[1].name = "Dragon";
    people[1].location = "Mars";

    people[2].name = "john";
    people[2].location = "Delhi";

    string key = get_string("Enter search word: ");

    int index = linear_search(people, arr_len, key);
    if (index != -1)
    {
        printf("Lives in %s\n", people[index].location);
    }
    else
    {
        printf("Not Found\n");
    }
}

int linear_search(person arr[], int l, string k)
{
    for (int i = 0; i < l; i++)
    {
        if (strcmp(arr[i].name, k) == 0)
        {
            return i;
        }
    }
    return -1;
}
```

## sorting
### Selection Sort --> O($n^2$), $\Omega$($n^2$), $\theta$($n^2$)
```MD
# Algorithm
For i from 0 to n-1:
    find smallest number between 0 and n-1
    swap number[i] with smallest number
```

```c
#include <cs50.h>
#include <stdio.h>

void selection_sort(int l, int arr[]);

int main(void)
{
    int l = 6, arr[] = {11, 5, 4, 2, 1, 6};
    selection_sort(l, arr);
}

void selection_sort(int l, int arr[])
{
    int smallest_position, temp;
    for (int i = 0; i < l; i++)
    {
        smallest_position = i;
        for (int j = i + 1; j < l; j++)
        {
            if (arr[j] < arr[smallest_position])
            {
                smallest_position = j;
            }
        }
        temp = arr[smallest_position];
        arr[smallest_position] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < l; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

```

### Bubble Sort --> O($n^2$), $\Omega$($n^2$) and $\Omega$($n$)
```md
# Algo -- usual way 
Repeat n-1 times:
    for i from 0 to n-1:
        if num[i] and num[i+1] are out of order:
            swap them


####################

# Algo - Optimal way
Repeat n-1 times:
    for i from 0 to n-1:
        if num[i] and num[i+1] are out of order:
            swap them
    if no swap:
        Quit
```

```c
#include <cs50.h>
#include <stdio.h>

void bubble_sort(int l, int arr[]);
void print_arr(int l, int arr[]);

int main(void)
{
    int arr[] = {1, 6, 2, 3, 4, 5}, l = 6;
    bubble_sort(l, arr);
}

void bubble_sort(int l, int arr[])
{
    int temp, swap;
    for (int i = 0; i < l - 1; i++)
    {
        swap = 0;
        for (int j = 0; j < l - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        // With optimization - this makes it stop sorting soreted array
        if (swap == 0)
        {
            break;
        }
    }
    print_arr(l, arr);
}

void print_arr(int l, int arr[])
{
    for (int i = 0; i < l; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

```

## Recursion:
- printing * pyramid with recursion.
```c
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int n = get_int("Height: ");
    draw(n);
}

void draw(int n)
{
    if (n <= 0)
        return;
    draw(n - 1);
    for (int i = 0; i < n; i++)
        printf("*");
    printf("\n");
}

/*
Output:

Height: 5
*
**
***
****
*****

*/

```

```c 
// binary search with recursion 
#include <cs50.h>
#include <stdio.h>

int binary_search(int first, int last, int arr[], int k);

int main(void)
{
    int l = 5, arr[] = {1, 2, 3, 4, 5}, k = get_int("Enter a number to search: ");
    if (binary_search(0, 5, arr, k) == 0)
    {
        printf("value %i is found.\n", k);
    }
    else
    {
        printf("value %i is not found.\n", k);
    }
}

int binary_search(int first, int last, int arr[], int k)
{
    if (first > last)
        return 1;

    int middle = first + (last - first) / 2;
    if (arr[middle] == k)
        return 0;
    else if (k < arr[middle])
        return binary_search(first, middle - 1, arr, k);
    else
        return binary_search(middle + 1, last, arr, k);
}

```

## Merge Sort - O(nlogn) - $\Omega$(nlogn)
```md
if only one number:
    quit
else:
    sort the left half
    sort the right half
    merge sorted halves
```

```c
#include <stdio.h>

void merge_sort(int arr[], int start, int end);
void merge_arr(int arr[], int start, int end);
void print_arr(int arr[], int l);

int main(void)
{
    int l = 8, arr[] = {5, 2, 7, 1, 3, 8, 6, 4};
    merge_sort(arr, 0, l - 1);
    print_arr(arr, l);
}

void merge_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    else
    {
        merge_sort(arr, start, start + (end - start) / 2);
        merge_sort(arr, start + (end - start) / 2 + 1, end);
        merge_arr(arr, start, end);
    }
}

void merge_arr(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int ls = start, le = mid, rs = mid + 1, re = end;

    int L[le - ls + 1], R[re - rs + 1];

    for (int i = 0; i <= le - ls; i++)
        L[i] = arr[ls + i];
    for (int i = 0; i <= re - rs; i++)
        R[i] = arr[rs + i];

    int i = 0, j = 0, l = start;
    while (i <= le - ls && j <= re - rs)
    {
        if (L[i] <= R[j])
        {
            arr[l] = L[i];
            i++;
        }
        else
        {
            arr[l] = R[j];
            j++;
        }
        l++;
    }
    // add other elements to array

    while (i <= le - ls)
    {
        arr[l] = L[i];
        i++;
        l++;
    }
    while (j <= re - rs)
    {
        arr[l] = R[j];
        j++;
        l++;
    }
}

void print_arr(int arr[], int l)
{
    for (int i = 0; i < l; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

```