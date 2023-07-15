#include "main.h"
/* Function to search database */
status search_database(mhash_t** arr)
{
	int flag = 1,i,index;
	char word[20];
	printf("\n");
	printf("Enter word to search: ");
	scanf("%s",word);
	index = toupper(word[0]) % 65;                                 //Find the hash table index
	if(index < 0 || index > 26)                                    
		index = 26;                                                //Update index if it is not character
	if(arr[index] == NULL)                                         //Check the index value is NULL or not
	{
		return e_failure;                                          //Return failure if value at index is NULL
	}

	mhash_t* temp = arr[index];
	shash_t* temp2 = temp -> mtoslink;
	while(temp)                                                    //Traverse through the main node
	{
		if(strcmp(temp -> word,word) == 0)                         //Check whether the word name are matching or not
		{
			flag = 0;	                                           //Update flag if word is found
			printf("The word '%s' is present in main on %d files\n",temp -> word,temp -> file_cnt);
			temp2 = temp -> mtoslink;
			while(temp2)                                           //Traverse throught the sub node
			{
				printf("In \"%s\" '%d' times\n",temp2 -> file_name,temp2 -> word_cnt);

				temp2 = temp2 -> slink;
			}

		}
		temp = temp -> mlink;
	}
	if(flag)                                                        //Return failure if word is not found
		return e_failure;

	printf("\n");
}
