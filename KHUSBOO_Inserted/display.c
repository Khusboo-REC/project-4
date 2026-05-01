#include "inverted_Search.h"

void display_database(Wlist *head[])
{
    printf("\n%-5s %-10s %-10s %-10s %-10s\n", 
           "Index", "Word", "FileCount", "Filename", "WordCount");
    printf("--------------------------------------------------------\n");
    
    for(int i = 0; i < 27; i++)
    {
        Wlist *temp = head[i];
        
        while(temp)
        {
            Ltable *l_temp = temp->Tlink;
            while(l_temp)
            {
                printf("%-5d %-10s %-10d %-10s %-10d\n", 
                       i, temp->word, temp->file_count, 
                       l_temp->file_name, l_temp->word_count);
                l_temp = l_temp->table_link;
            }
            temp = temp->link;
        }
    }
    printf("--------------------------------------------------------\n");
}