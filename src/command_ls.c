#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "../Header.h"

void command_ls (char ** arg)
{
	if(arg[1] != NULL && strcmp(arg[1],"&")==0)
	{
		int i;
		for(i=1;arg[i] != NULL; i++)
			arg[i] = arg[i+1];
	}
	int i;
	struct dirent **list;
	int index;
	char *temp = (char*)malloc(sizeof(char)*100);
	for(i=0;arg[i]!=NULL;i++)
	{	
		if(strcmp(arg[i],"-a") != 0 && strcmp(arg[i],"-l") != 0 && strcmp(arg[i],"-al") != 0 && strcmp(arg[i],"-la") != 0)
			temp = arg[i];
	}
	int flag=0;
	if(strcmp(temp,"ls") == 0)
		index = scandir(".",&list,NULL,alphasort);
	else
	{
		index = scandir(temp,&list,NULL,alphasort);
		flag=1;
	}

	int hidden=0;
	int extended=0;

	for(i=1;arg[i] != NULL;i++)
	{
		if(strcmp(arg[i],"-a")==0)
			hidden=1;
		if(strcmp(arg[i],"-l")==0)
			extended=1;
		if(strcmp(arg[i],"-la")==0)
		{
			hidden=1;
			extended=1;
		}
		if(strcmp(arg[i],"-al")==0)
		{
			hidden=1;
			extended=1;
		}
	}
	// printf("%d\n", index);
	while(index>0)
	{
		index--;
		char *pth = (char*)malloc(sizeof(char)*100);
		if(flag==1)
			strcpy(pth,temp);
		else
			strcpy(pth,list[index]->d_name);
		if(hidden==1)
		{	
			if(extended == 1)
			{
				details(pth);
				printf("\t%s\n", list[index]->d_name);
			}else
				printf("%s\n", list[index]->d_name);
			free(list[index]);
		}else
		{
			if(strcmp(list[index]->d_name,"..") != 0 && strcmp(list[index]->d_name,".") !=0)
			{
				if(extended == 1)
				{	
					details(pth);
					printf("\t%s\n", list[index]->d_name);	
				}else
					printf("%s\n", list[index]->d_name);
				free(list[index]);
			}		
		}
	}
	free(list);
}