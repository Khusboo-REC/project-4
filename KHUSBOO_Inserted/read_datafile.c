#include "inverted_Search.h"

Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if(!fptr)
        return NULL;

    char word[WORD_SIZE];
    char clean_word[WORD_SIZE];

    while(fscanf(fptr, "%s", word) != EOF)
    {
        // Clean the word - remove punctuation and convert to lowercase
        int j = 0;
        for(int i = 0; word[i] && i < WORD_SIZE-1; i++)
        {
            if(isalpha(word[i]))
            {
                clean_word[j++] = tolower(word[i]);
            }
        }
        clean_word[j] = '\0';
        
        // Skip if word becomes empty after cleaning
        if(j == 0)
            continue;
            
        int index = hash_function(clean_word);
        update_word_count(&head[index], clean_word, filename);
    }

    fclose(fptr);
    return NULL;
}