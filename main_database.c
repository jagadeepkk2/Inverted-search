/*
Name:Jagadeep K K
Description: P1 - Inverted Search
The purpose of storing an index is to optimize speed and performance in
finding relevant documents for a search query. Without an index, the search
engine would scan every document in the corpus, which would require
considerable time and computing power.
Date:21/06/23
 */

#include "main.h"

int main(int argc,char* argv[])
{
	int i,j,state;
	char ch;
	File *head = NULL;
	mhash_t* arr[HASHMAX];
	for(j=0;j < HASHMAX;j++)
	{
		arr[j]=NULL;
	}

	if(argc < 2)                                            
	{
		printf("Error:Please pass more than 2 arguments\n");
		return FAILURE;
	}
	for(i = 1;i < argc;i++)
		if(read_and_validate(&head,argv[i]) == e_success)
		{
			printf("%s Read and validate successful\n",argv[i]);
			state = open_files(argv[i]);
			if(state == e_success || state == EMPTY_FILE)
			{
				if(state == e_success)
				{
					printf("%s Open files successful\n",argv[i]);
					if(insert_sll(&head,argv[i]) == e_success)
					{
						printf("%s Insert to sll successful\n\n",argv[i]);

					}
					else
					{

						printf("Insert to sll failed\n");
						return FAILURE;

					}
				}
				else
				{

					printf("%s is empty file not added to list\n",argv[i]);
				}
			}
			else
			{

				printf("Open files failed\n");
				return FAILURE;
			}
		}
		else
		{
			printf("Read and validate failed\n");
			return FAILURE;
		}
	do
	{
		int choice;
		printf("1.Create database\n2.Display database\n3.Search\n4.Save\n5.Update\n6.Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(create_database(&head,arr) == e_success)
				{
					printf("\n!!! Database created successfully !!!\n\n");

				}
				else
				{
					printf("\n%s add to database failed\n",argv[i]);
				}
				break;
			case 2:

				view_database(&head,arr);

				break;
			case 3:

				if(	search_database(arr) != e_failure)
				{
					printf("SEARCH COMPLETED SUCCESSFULLY\n");
				}
				else
				{
					printf("SEARCH FAILED:WORD NOT FOUND\n");
				}

				break;
			case 4:
				char backup[20];
				printf("Enter the file name to save : ");
				scanf("%s",backup);
				if(strstr(backup,".txt")== NULL)
				{
				printf("Please enter .txt file\n");
				break;
				}
				if(strcmp(strstr(backup,".txt"),".txt") != 0)
				{
					printf("Please enter .txt file\n");
					break;
				}
				backup_database(arr,backup);
				printf("!!!Database backup completed Successfully !!!\n");
				break;
			case 5:
				char update[20];
				printf("Enter the backup file name : ");
				scanf("%s",update);
				if(strstr(update,".txt")== NULL)
				{
				printf("Please enter .txt file\n");
				break;
				}
				if(strcmp(strstr(update,".txt"),".txt") != 0)
				{
					printf("Please enter .txt file\n");
					break;
				}
					FILE* fp = fopen(update,"r");
				if(fp == NULL)
				{
					printf("File open failed\n");
					return FAILURE;
				}
				update_database(fp,arr); 
				printf("!!!Database updated Successfully !!!\n");
				break;
			case 6:
			default:
				return 0;
		}
		printf("Do you want to continue(Y/y): ");
		__fpurge(stdin);
		scanf("%c",&ch);
	}while(ch == 'Y' || ch == 'y');

}
