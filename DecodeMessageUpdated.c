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

/*
 *  assumptions
 *  - only newline characters cause numberOfLines to be incremented.
 *    (so only 2 lines are counted but 3 are shown on output)
 *  
 *  limitations
 *  - only an even number of characters in the message are processed. an odd
 *    number of characters in a message result in the last odd character being ignored
 *  - if errors are encountered the program ends.
 *
 */

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

/*
 * myToUpper
 *
 * if ascii character is lower case return it in upper case
 *
 */

char myToUpper(const char c)
{
  if ('a' <= c && c <= 'z')
  {
    return c - 'a' + 'A'; // calculates and returns upper case
  }

  return c;
}

/* 
 * isHexDigit
 *
 * check if ascii character is a valid hex character
 * 
 * return 0 FALSE
 * return 1 TRUE
 */

int isHexDigit(const char c)
{
  char temp = myToUpper(c);
  
  if(('0' <= temp && temp <= '9') || ('A' <= temp && temp <= 'F'))
  {
    return 1;
  }

  return 0; 
}

/* 
 * hexToAscii
 *
 * if c is a hex digit, subtract offset and pass it out via *pOutput
 * 
 * return 0 success
 * return 1 failure
 *
 */ 

int hexToAscii(const char c, char *pOutput)
{
  char temp = myToUpper(c);
  if(!pOutput)
  {
    printf("Error in hexToAscii: *pOutput is NULL\n");
    
    return 1;
  }

  if(!isHexDigit(temp))
  {
    printf("Error in hexToAscii: not a hex number\n");
    
    return 1;
  }
  
  if('0' <= temp && temp <= '9')
  {
    *pOutput = temp - '0'; 
  }
  else if ('A' <= temp && temp <= 'Z')
  {
    *pOutput = temp - 'A' + 0xA;
  }

  return 0;
}

/*
 * asciiHexToAscii
 *
 * converts 2 ascii encoded hex numbers into a hex number interpreted as ascii
 * converted number is passed out via pOutput
 * return 0 success
 * return 1 failure
 *
 */

int asciiHexToAscii(const char *pMessage, const int index, char *pOutput)
{
  if(!pOutput)
  {
    printf("Error in asciiHexToAscii: *pOutput is NULL\n");
    
    return 1;
  }

  if(!pMessage)
  {
    printf("Error in asciiHexToAscii: *pMessage is NULL\n");
    
    return 1; 
  }

  char temp[2] = { pMessage[index], pMessage[index +  1] };
  
  if(hexToAscii(temp[0], &temp[0]) || hexToAscii(temp[1], &temp[1]))
  {
    return 1;
  }
  
  *pOutput = (temp[0] << 4) + temp[1];

  return 0; 
}

/*
 * DecodeAndPrint() 
 *
 * decodes a single message
 *
 * returns number of counted newlines
 *
 */

int DecodeAndPrint(const char *pMessage)
{
  /*
  * Walk through the message.
  * print each character, print new lines, and stop printing the message
  * at the end of the message text, according to the special characters.
  */

  int i = 0;
  int error = 0;
  int numberOfLines = 0;
  
  if(!pMessage)
  {
    printf("Error in DecodeAndPrint: *pMessage is NULL\n");
    return 0; // returns 0 because no lines are parsed
  }
 
  for(i = 0; pMessage[i]; ++i) // Walk through the message.
  {
    if(i % 2 == 1) // check characters 2 at a time
    {
      char temp[2] = {myToUpper(pMessage[i - 1]), myToUpper(pMessage[i])};
      
      if(temp[0] == 'E' && temp[1] == 'F')
      {
        ++numberOfLines;
        printf("\n"); // print newline
      }
      else if(temp[0] == 'F' && temp[1] == 'F')
      {
        return numberOfLines; // stop printing the message and return
      }
      else
      {
        char ascii = 0;  
        
        error = asciiHexToAscii(pMessage, i - 1, &ascii);
        
        if(!error) 
        {
          printf("%c", ascii);// print each character to stdout
        }
        else
        {
          printf("Error in DecodeAndPrint. Cowardly running away!n");
          return numberOfLines;
        }
      }
    }
  }

  /* Correct this code to return the number of lines printed from the message */
  return numberOfLines;
}

int main()
{
  int qty = 0;
  
  printf("\nMessage:\n\n%s\n", pMessage);
  printf("\nParsed message:\n\n");
  qty = DecodeAndPrint(pMessage);
  printf("\n\nNumber of lines that were parsed: %d\r\n", qty);

  return 0;
}
