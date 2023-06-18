// Finish this program so that content from pMessage is converted from ASCII 
//   encoded hexadecimal to ASCII characters.
// Only printf() may be used from C standard libraries. No other library funcitons may be used.
// Helper functions may be added.
// Include appropriate error handling.
// State any assumptions you have made and any limitations of your solution.
// The remaining comments should be sufficient to understand the exercise.
// The program must compile and execute without error.

// pMessage contains a message in ASCII encoded hexadecimal format.
// Example: The characters "41" convert to 0x41 or 'A' ASCII.
// Special characters for this exercise: EF is a line ending, FF ends the message.

#include "stdio.h"

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

char myToUpper(const char c)
{
  if (c >= 'a' && c <= 'z')
  {
    return c - 'a' + 'A';
  }

  return c;
}

int isHexDigit(const char c)
{
  if((c >= '0' && c <= '9') || (c  >= 'A' && c <= 'F'))
  {
    return 1;
  }

  return 0;
}

char hexToAscii(const char c)
{
  char temp = myToUpper(c);
  
  if(isHexDigit(temp))
  {
    if(temp >= '0' && temp <= '9')
    {
      return temp - '0';
    }
    else if (temp >= 'A' && temp <= 'Z')
    {
      return temp - 'A' + 10;
    }
  }

  printf("Error!\n");

  return -1;
}

char asciiHexToAscii(const char *pMessage, const int index)
{
  if(!pMessage)
  {
    return -1;
  }

  char hex[2] = { pMessage[index], pMessage[index +  1] };
  hex[0] = hexToAscii(hex[0]);
  hex[1] = hexToAscii(hex[1]);

  return (hex[0] << 4) + hex[1]; 
}

// DecodeAndPrint() decodes a single message
int DecodeAndPrint(const char *pMessage)
{
  /*
  * Walk through the message.
  * print each character, print new lines, and stop printing the message
  * at the end of the message text, according to the special characters.
  */

  int i = 0;
  int numberOfLines = 0;
  
  if(pMessage == NULL)
  {
    printf("\nError, no message!");
    
    return 0; // returns 0 because no lines are parsed
  }
 
  for(i = 0; pMessage[i]; ++i) // Walk through the message.
  {
    if(i % 2 == 1) // check characters 2 at a time
    {
      if(pMessage[i - 1] == 'E' && pMessage[i] == 'F')
      {
        ++numberOfLines;
        printf("\n"); // print new lines
      }
      else if(pMessage[i - 1] == 'F' && pMessage[i] == 'F')
      {
        return numberOfLines; // stop printing the message and return
      }
      else
      {
        printf("%c", asciiHexToAscii(pMessage, i - 1));// print each character to stdout
      }
    }
  }

  /* Correct this code to return the number of lines printed from the message */
  return numberOfLines;
}

int main()
{
  int qty = 0;
  
  printf("\nMessage:\n%s\n", pMessage);
  printf("\nParsed message:\n");
  qty = DecodeAndPrint(pMessage);
  printf("\n\nNumber of lines that were parsed: %d\r\n", qty);

  return 0;
}
