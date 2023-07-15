#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <stdio_ext.h>
#define SUCCESS 1
#define FAILURE 0
#define HASHMAX 27
#define EMPTY_FILE 2
typedef struct subnode
{
    int word_cnt;
    char file_name[20];
    struct subnode *slink;
}shash_t;

typedef struct mainnode
{
    int file_cnt;
    char word[20];
    struct subnode *mtoslink;
    struct mainnode *mlink;

}mhash_t;
typedef enum _status
{
  e_failure, 
  e_success
}status;
typedef struct _File
{
	char filename[20];
	struct _File* next;
}File;
status read_and_validate(File**,char *);
status open_files(char *);
status insert_sll(File **,char *);
status create_database(File **,mhash_t**);
status view_database(File**,mhash_t**);
status search_database(mhash_t** arr);
status backup_database(mhash_t** arr,char*);
status update_database(FILE*,mhash_t**);
