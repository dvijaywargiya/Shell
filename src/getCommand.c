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

char ** getCommand(char *inp)
{
	int size=1024,index=0;
	char **commands = malloc(sizeof(char)*size);
	char *str;
	str = strtok(inp," \t\n");
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
			str = strtok(NULL," \t\n");
		}else
		break; 
	}
	commands[index] = NULL;
	free(str);
	return commands;
}