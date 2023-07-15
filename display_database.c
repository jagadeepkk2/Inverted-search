#include "main.h"
/* Function to display database */
status view_database(File** head,mhash_t** arr)
{
	int i,flag = 1;
	for(i = 0;i < 27;i++)                         //Check whether the hashtable is empty or not
	{
		if(arr[i] != NULL)
		{
			flag = 0;
		}
	}
	if(flag)
	{
		printf("Database is empty\n");
		return e_failure;
	}

	printf("\n   DATABASE\n");
	printf("   --------\n\n");
	i=0;
	printf("%10s\t%10s\t%10s\t%10s\t%10s\n","[index]","[word]","[filecount]","[filename]","[wordcount]");
	for(i = 0;i < 27;i++)                          //Traverse thorugh hashtable
	{
		mhash_t* temp = arr[i];
		while(temp)                                //Traverse through main nodes and display data
		{
			/* Display index and word */
			printf("%8d\t %8s\t",i,temp -> word);
			/* Display filecount */
			printf("%d file(s)\t",temp -> file_cnt);
			shash_t* temp2 = temp -> mtoslink;
			while(temp2)                            //Traverse through sub nodes and display data
			{
				/* Display file name*/
				printf("file %6s\t ",temp2 -> file_name);
				/* Display word count*/
				printf("%2d time(s)\t",temp2 -> word_cnt);

				temp2 = temp2 -> slink;
			}
			printf("\n");
			temp = temp -> mlink;
		}
	}
}
