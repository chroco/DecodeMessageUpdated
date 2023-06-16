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
int DecodeAndPrint(char const *pMessage)
{
    /*
    * Walk through the message.
    * print each character, print new lines, and stop printing the message
    * at the end of the message text, according to the special characters.
    */

    /* Correct this code to return the number of lines printed from the message */
    return 0;
}

int main()
{
    int qty;
    qty = DecodeAndPrint(pMessage);

    printf("Number of lines that were parsed: %d\r\n", qty);
}
