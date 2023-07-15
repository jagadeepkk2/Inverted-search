#include "main.h"
/* Function to backup database */
status backup_database(mhash_t** arr,char *bkpstr)
{
	int i;
	FILE* fp;
	char buf[2];
	fp = fopen(bkpstr,"w+");                            //Open the backup file in write mode
	if(fp == NULL)
	{
		printf("fopen failed\n");
		return e_failure;
	}
	mhash_t* temp;
	shash_t* temp2;
	for(i = 0;i < 27;i++)                               //Traverse through hashtable
	{
		if(arr[i] == NULL)                              //skip array index without main node
			continue;

		fprintf(fp,"#%d;",i);                           //Create backup file in given format

		fprintf(fp,"%s","\n");
		temp = arr[i];
		while(temp)
		{

			fprintf(fp,"%s;%d;",temp -> word,temp->file_cnt);
			temp2 = temp -> mtoslink;
			while(temp2)
			{

				fprintf(fp,"%s;%d;#",temp2->file_name,temp2->word_cnt);
				
				temp2 = temp2 -> slink;
			}

			temp = temp -> mlink;

			fprintf(fp,"%s","\n");
		}

	}

	fclose(fp);
}
