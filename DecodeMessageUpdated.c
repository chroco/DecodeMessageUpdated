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
#include "ctype.h"
#include "inttypes.h"

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

// DecodeAndPrint() decodes a single message
int OldDecodeAndPrint(char const *pMessage)
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

  return numberOfLines;  
}

char asciiHexToAscii(const char *pmessage, const int index)
{
//  int i = 0;
  uint8_t test = 0x0;
  uint8_t base = (1 << 4);

  char hex[3] = { pmessage[index * 2], pmessage[index * 2 + 1], '\0' };
  test = (char)((uint8_t)(hex[0] - '0') * base  + (uint8_t)(hex[1] - '0')); 
  //printf("%c", (char)test); 
/*
  printf("\n");
  printf("ascii: %c, %c\n", hex[0], hex[1]); 
  printf("hex:  0x%02x. 0x%02x\n", hex[0], hex[1]); 
  printf("uns:  %u. %u\n", hex[0], hex[1]); 
  printf("hex : %x\n", test); 
  printf("ascii : %c\n", (char)test); 
//*/
/*
  for (i = 0; i < 2; ++i)
  {
    char hex[3] = { pmessage[i * 2], pmessage[i * 2 + 1], '\0' };
    test = (hex[0] << 4) | hex[1]; 
  }
//*/
  return test;
}

int toAsciiStdOut(uint8_t val)
{
  if(sizeof(char) != sizeof(uint8_t))
  {
    printf("type size mismatch error!\n");
    return 1;
  }

  const char highchar = '4';
  const char lowchar = '1';
  uint8_t h4bits = 0x0;
  uint8_t l4bits = 0x0;

  printf("\n\n");
  printf("char     : %c\n", val);
  printf("uint8_t  : %04u\n", val);
  printf("hex      : %04x\n", val);
  
  return 0;
}

// DecodeAndPrint() decodes a single message
int DecodeAndPrint(char const *pMessage)
{
  /*
  * Walk through the message.
  * print each character, print new lines, and stop printing the message
  * at the end of the message text, according to the special characters.
  */
  int i = 0;
  int numberOfLines = 0;
  
  //printf("\nMessage:\n%s\n", pMessage);
 
  printf("\n\nParsed message:\n");
  
  if(pMessage == NULL)
  {
    printf("\nError, no message!");
    
    return 0; // returns 0 because no lines are parsed
  }
 
  for(i = 0; pMessage[i]; ++i) // Walk through the message.
  {
    if(i % 2 == 1) // check characters 2 at a time
    {
      printf("%c", asciiHexToAscii(pMessage, i - 1)); // print each character to stdout
     /* 
      if(toupper(pMessage[i - 1]) == 'E' && toupper(pMessage[i]) == 'F')
      {
        ++numberOfLines;
        printf(" \\n\n"); // print new lines
      }
      else if(toupper(pMessage[i - 1]) == 'F' && toupper(pMessage[i]) == 'F')
      {
        return numberOfLines; // stop printing the message and return
      }
      */
    }
  }


  //toAsciiStdOut('A');

  /* Correct this code to return the number of lines printed from the message */
  return numberOfLines;
}

int main()
{
  int qty;
  qty = OldDecodeAndPrint(pMessage);
  qty = DecodeAndPrint(pMessage);
//  asciiHexToAscii(pMessage, 0);

  printf("\n\nNumber of lines that were parsed: %d\r\n", qty);

  return 0;
}
