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

char ** seprateSemi(char *inp)
{
	int size=32,index=0;
	char **commands = malloc(sizeof(char)*size);
	char *str;
	str = strtok(inp,";");
	while(1)
	{
		if(str != NULL)
		{
			commands[index++] = str;
			if(index>=size)
			{
				size*=2;
				commands=realloc(commands,size);
			}
			str = strtok(NULL,";");
		}else
		break; 
	}
	commands[index] = NULL;
	free(str);
	return commands;
}