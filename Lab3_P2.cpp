/*
* C++ code that implements a reverse character function and a concatinate function which are then called in main function
* CECS 275 - Spring 2022
* @Everardo Camarena
* @Calvin Veith
* version 1.0.0
*/

#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

//reverse function
void reverse(char s[])
{

    //grab the length of s
    int length = strlen(s);

    //define variables to keep track of the position of our array/string elements
    int c, i, j;

    //store our original string in c, then grab each element in string s[j] (reverse) and place it into c
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

//concatenation function
void concat(const char a[], const char b[], char result [], int result_maxlength)
{
    //create variable to store the length of our character a
    int n = strlen(a);

    //copies a specified bytes of characters from source to destination.
    strncpy(result, a, result_maxlength);
    if(n < result_maxlength)
    {
        strncat(result, b, result_maxlength - n);
    }
    //stores the size of our concatenated word
    result[result_maxlength] = '\0';
}

int main()
{
    //hardcode what gets inputed into our reverse function
    char s[] = "hello";
    cout << "Original string: " << s << endl;

    //call reverse function
    reverse(s);

    //display our results to terminal
    cout << "Reverse string: " << s << endl;
    cout << endl;
    
    
    //hardcode what gets inputed into our concat function and our desired result_maxlength
    char a[] = "chicken";
    char b[] = "waffle";
    //size of our whole string including "\0"
    char c[6];
    char d[11]; 
    char e[21];

    //call concat function and the desired size of our new concatenated string
    concat(a, b, c, 5);
    concat(a, b, d, 10);
    concat(a, b, e, 20);

    //display our results to terminal
    cout << "result_maxlength = 5: " << c << endl;
    cout << "result_maxlength = 10: " << d << endl;
    cout << "result_maxlength = 20: " << e << endl;
    cout << endl;
    return 0;
}