// Finish this program so that content from pMessage will converted to ASCII 
// and output preferably to a console.
// If there are bugs, solve the bugs.
// Add any appropriate error handling.
// State any assumptions you have made and any limitations of your solution.
// The remaining comments should be sufficient to understand the exercise.

// Use only libraries provided natively with your compiler.

#include <stdio.h>
#include <ctype.h>

#ifndef NULL
#define NULL (void *0)
#endif // #ifndef NULL

// *pMessage[] contains a message in ASCII encoded hexadecimal format.
// Special characters for this exercise: EF is a line ending, FF ends the message.

char const * pMessage = {
  "436F6E67726174756C6174696F6E732120596F75"
  "20686176652074686520656E636F64696E672E"
  "EF4974206973207265616C6C7920676F6F6420"
  "746F2070617273652065616368206C696E652E"
  "EF476F6F642120546869732073686F77732065"
  "7874726120696E73696768742EFF5768656E20"
  "77696C6C20746865206D657373616765206265"
  "206F7665723F20436865636B21EF"
};

/*
 *  Assumptions
 *  - Code is written in C not C++ so #include <iostream> is incorrect
 *
 *  - *pMessage[] in the instructions is unnessesary since
 *    there is only a single message to be handled
 *
 *  - the message is complete and nothing was lost in transmission
 *
 *  - compiler appends the null bite to *pMessage string literal
 *
 *  - No conversion from hex to ASCII is required since the message is 
 *    given in ASCII characters
 *  
 *  - 2 characters are required to be read in order to test for 
 *    special characters. This ensures sequences such as "EFF" 
 *    will not be interpreted as both a newline and end of message.
 *
 *  - FF is not counted as a newline even though it looks like this in the
 *    console.
 *
 *  Limitations
 *  - this code does not test for a valid message
 *
 *  - expects an even number of characters and ignores a trailing odd
 *    character if it exists
 *
 *  - no ECC for the message
 *
 *  Compiler and options
 *  - used gcc version 9.4.0 with -g -Wall -Wextra -Wno-unused-parameterc flags
 *  
 */

// DecodeAndPrint() decodes a single message
int DecodeAndPrint(char const *pMessage)
{
  int i;
  int numberOfLines = 0;
    
  if(pMessage == NULL)
  {
    printf("\nError, no message!");
    
    return 0; // returns 0 because no lines are parsed
  }

  printf("\nMessage:\n%s\n", pMessage);
 
  printf("\nParsed message:\n");
  
  for(i = 0; pMessage[i]; ++i) // Walk through the message.
  {
    if(!isxdigit(pMessage[i])) // checks to verify the char is a hexidecimal digit
    {
      printf("\nError, %c not recognized as a hexidecimal number", pMessage[i]);
  
      return numberOfLines;
    }
        
    printf("%c", pMessage[i]); // print each character to stdout
    
    if(i % 2 == 1) // check characters 2 at a time
    {
      if(toupper(pMessage[i - 1]) == 'E' && toupper(pMessage[i]) == 'F')
      {
        ++numberOfLines;
        
        printf(" \\n\n"); // print new lines
      }

      if(toupper(pMessage[i - 1]) == 'F' && toupper(pMessage[i]) == 'F')
      {
        return numberOfLines; // stop printing the message and return
      }
    }
  }

  printf("\nEnd of characters, no end of message (FF) received!\n"); 

  return numberOfLines; // corrected return statement for the number of lines printed from the message
}

int main()
{
  int qty = 0; // ensure qty is initialized

  qty = DecodeAndPrint(pMessage);

  printf("\n\nNumber of lines that were parsed: %d\r\n", qty);

  return 0; // added return statement
}

