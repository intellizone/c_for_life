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

## strings in c
```c
#include <string.h>

int strlen(char *string);
```
