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

char * readCommand(void)
{
	int size=100,index=0;
	char *command = malloc(sizeof(char)*size),temp;
	int i;
	while(1)
	{
		temp = getchar();
		if(temp != EOF && temp != '\n')
		{
			command[index++]=temp;
		}else
		{
			command[index++] = '\0';
			return command;
		}
		if(index+1>=size)
		{
			size*=2;
			command = realloc(command,size);
		}
	}
	free(command);
}