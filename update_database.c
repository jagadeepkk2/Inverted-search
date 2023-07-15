#include "main.h"
/* Function to update database */
status update_database(FILE* fp,mhash_t** arr)
{

	int index,flag=0,count=0,file_cnt,word_cnt;
	char str[50];
	char del[2] = ";";
	char *token;
	char word[20];
	char file_name[20];
	while(fscanf(fp,"%s",str))                         //Read strings from given backup file            
	{
		flag = 0;
		if(feof(fp))                                   //Check whether the end of file is reached or not
		{
			break;
		}


		token = strtok(str,del);                        //fetch first line 


		if(token[0] == '#')                              
		{
			index = atoi(&token[1]);                    //Fetch the index value
			continue;
		}
		while(token != NULL)
		{

			if(token[0] != '#')
			{
				switch(count)
				{
					case 0:
						strcpy(word,token);             //Fetch word
						count++;
						break;
					case 1:
						file_cnt = atoi(token);         //Fetch file count
						count++;
						break;
					case 2:

						strcpy(file_name,token);         //Fetch file name
						count++;
						break;
					case 3:

						word_cnt = atoi(token);          //Fetch word count
						count++;
						break;

				}
			}
			else
			{
				if(token[1] == '\0')                     //Check whether end of line comes after # or not
				{
					count = 0;                           //Update count value
					break;
				}
				strcpy(file_name,token + 1);             
				count = 3;
			}

			if(count == 4)                               //Check whether 4 values fetched or not
			{
				mhash_t* main;
				if(flag == 0)                             //Check new line or not
				{
					 main=malloc(sizeof(mhash_t));
                     main -> file_cnt = file_cnt;
					 strcpy(main -> word,word);
						main -> mlink = NULL;
						shash_t* sub = malloc(sizeof(shash_t));
						sub -> word_cnt = word_cnt;
						strcpy(sub -> file_name,file_name);
						sub -> slink = NULL;
						main -> mtoslink = sub;
					if(arr[index] == NULL)               //Check first main node or not
					{
						arr[index] = main;               //Link first main node to hashtable
						flag = 1;
					}
					else
					{
						mhash_t* temp = arr[index];      //Traverse and link other main nodes  
						mhash_t* pre = arr[index];
						while(temp)                     
						{
							pre = temp;
							temp = temp -> mlink;
						}

						pre -> mlink = main;
						flag = 1;
					}

				}
				else
				{
					shash_t* sub = malloc(sizeof(shash_t));  //Link subnodes to main nodes
					sub -> word_cnt = word_cnt;
					strcpy(sub -> file_name,file_name);

					shash_t* temp = main -> mtoslink;
					shash_t* pre = main -> mtoslink;
					while(temp)
					{
						pre = temp;
						temp = temp -> slink;
					}
					pre -> slink = sub;

				}

			}
			token = strtok(NULL,del);                         //Fetch next word based on delimeter 

		}
	}
}
