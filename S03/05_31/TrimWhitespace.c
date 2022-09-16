/*
7) Напишете C програма за отрязване както на водещите, така и на крайните символи за
празно пространство в низ с помощта на цикъл.
*/

#include <stdio.h>
#include <string.h>

void trimLeadingSpaces(char *string);
void trimTrailingSpaces(char *string);
char *strrev_(char *str); // stolen

/*
Please note:

The two functions are written in different styles
for the sake of demonstration. In real situations
we should pick one for the entire program.

This includes
 - using a pointer vs. an index,
 - in-/decrementing in the assignment statement
   or afterwards ( a = b++;  vs.  a = b; b++; )
*/

int main ()
{
    char string[100] ="  Hello world  ";

    printf("Initial string:      '%s'\n", string);

    trimLeadingSpaces(string);
    printf("After leading trim:  '%s'\n", string);

    trimTrailingSpaces(string);
    printf("After trailing trim: '%s'\n", string);
}

///////////////////////////////////////////////////////////

void trimLeadingSpaces(char *string)
{
    char *front = string;
 
    // Find the first meaningful char
    while ((*front == ' ') || (*front == '\t'))
    {
        front++;
    }

    // Copy meaningful part up until the end
    while (*front != '\0')
    {
        *(string++) = *(front++);
    }
    *string = '\0';
}

void trimTrailingSpaces(char *string)
{
    size_t back = 0;
    while (string[back] != '\0')
    {
        back++;
    }
    back--; // We reached '\0', ignore it

    while ((string[back] == ' ') || (string[back] == '\t'))
    {
        string[back] = '\0';
        back--;
    }
}

//////////////// Stolen from StackOverflow ////////////////
char *strrev_(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = (str + strlen(str) - 1);
           p2 > p1;
           ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
