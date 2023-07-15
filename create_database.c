#include "main.h"
/* Function to create database */
status create_database(File **head,mhash_t** arr)
{
    char word[20];
    int index;
	FILE *fp;
	if(*head == NULL)                                          //Check whether  the linked list is empty or not
		return e_failure;

	File *templ=*head;
	while(templ)
	{
		fp=fopen(templ->filename,"r");                         //Open file in read mode
		if(fp == NULL)
		{
			printf("File open failed\n");
			return e_failure;
		}
		while(fscanf(fp,"%s",word))                            //Scan words from file
		{
			if(feof(fp))                                       //Check whether the end of file is reached or not 
				break;
			index=toupper(word[0])%65;                         //Get hashtable index
			if(index<0 || index > 26)                          //Check whether it is character or not
				index=26;                                      //Store index if it is not a character
			if(arr[index]==NULL)                               //Check whether it is first main node or not
			{

				shash_t* sub=malloc(sizeof(shash_t));          //Create first main node and subnodes
				mhash_t* main=malloc(sizeof(mhash_t));
				main -> file_cnt = 1;
				strcpy(main->word,word);
				main -> mtoslink = sub;
				sub -> word_cnt = 1;
				strcpy(sub->file_name,templ->filename);
				sub ->slink = NULL;
				main -> mlink = NULL;
				arr[index]=main;

			}
			else
			{

				mhash_t* temp=arr[index];                       
				mhash_t* prev=arr[index];
				while(temp)                                    //Traverse through the main node
				{
					if(strcmp(temp -> word,word)==0)           //check whether the word name matching or not

					{
						int flag1=1;
						shash_t* sub=malloc(sizeof(shash_t));  
						sub -> slink = NULL;
						shash_t* temp1=temp->mtoslink;
						shash_t* sprev=temp->mtoslink;
						while(temp1)                            //Traverse through subnode
						{

							if(strcmp(temp1->file_name,templ -> filename)==0)         //Check whether the file names are matching 
							{
								(temp1->word_cnt)++;                                  //Increment word count
								flag1=0;					                          //Update flag if file names matching
								break;

							}


							sprev=temp1;
							temp1=temp1->slink;
						}
						if(flag1)                                                      //Check files names matched or not
						{
							strcpy(sub->file_name,templ->filename);                    
							sub->word_cnt=1;                                           //Increment word count
							sprev->slink=sub;                                          //Link subnode to last
							(temp->file_cnt)++;                                        //Increment file count in main node
							break;
						}
						else
						{
							break;
						}

					}
					prev=temp;			
					temp=temp->mlink;

				}
				if(temp==NULL)                                                         //Add new main node if words are not matching
				{
					shash_t* sub=malloc(sizeof(shash_t));                               
					mhash_t* main=malloc(sizeof(mhash_t));                              
					main -> file_cnt = 1;
					strcpy(main->word,word);
					main -> mtoslink = sub;
					sub -> word_cnt = 1;
					strcpy(sub->file_name,templ->filename);
					sub ->slink = NULL;
					main -> mlink = NULL;
					prev-> mlink=main;                                                  //Link main node to main node list
				}

			}


		}
		templ = templ -> next; 
	}
	return e_success;
}
