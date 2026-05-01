#include "inverted_Search.h"

int hash_function(const char *word)
{
    if(word == NULL || word[0] == '\0')
        return 26;  // Return index 26 for empty string
    
    // Handle non-alphabetic first characters
    if(!isalpha(word[0]))
        return 26;  // Use index 26 for all non-alphabetic words
        
    return tolower(word[0]) - 'a';  // Returns 0-25 for a-z
}