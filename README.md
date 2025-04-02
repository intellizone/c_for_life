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

```

### Bubble Sort
```md
# Algo
Repeat n-1 times:
    for i from 0 to n-1:
        if num[i] and num[i+1] are out of order:
            swap them
```

```c
```