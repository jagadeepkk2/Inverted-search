#include "main.h"
/* Function to read and validate arguments */
status read_and_validate(File** head,char *str)
{
	int i = 1;
if(strstr(str,"txt")==NULL)
{
	return e_failure;
}
	if(strcmp(strstr(str,".txt"),".txt") != 0)
		return e_failure;
	else
	{
		File* temp=*head;
		while(temp)
		{
			if(strcmp(temp->filename,str)==0)
			{
				printf("Error: %s is duplicate file\n",str);
				return e_failure;
			}
			temp=temp->next;
		}

		return e_success;
	}
}

/* Function to open files */
status open_files(char *str)
{	
	FILE* fp;
	fp=fopen(str,"r");
	if(fp==NULL)
	{
		printf("FIle doesnot exist\n");
		return e_failure;
	}

	fseek(fp,0,SEEK_END);
	if(ftell(fp)==0)
	{

		printf("ERROR:%s is empty file\n",str);	 

		return EMPTY_FILE;
	}

	return e_success;
}

/* Function to insert file names to single linked list */
status insert_sll(File **head,char *argv)
{
	File *new = malloc(sizeof(File));
	if(new==NULL)
		return e_failure;
	strcpy(new -> filename,argv);
	new -> next = NULL;

	if(*head == NULL)
	{
		*head = new;
		return e_success;
	}
	File *temp = *head;

	while (temp->next)
	{

		temp = temp ->next;
	}
	temp->next = new;


	return e_success;
}




