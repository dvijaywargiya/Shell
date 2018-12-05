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

void command_cd (char ** arg)
{
	if(arg[1] != NULL && strcmp(arg[1],"&")==0)
		arg[1] = NULL;
	char temp[1024];
	if(arg[1] != NULL)
	{	
		getcwd(temp,sizeof(temp));
		if (strcmp(arg[1],"..") == 0 && strcmp(temp,original_path)==0)
		{
			printf("Sorry, you can't go back from this directory.\n");
			return;
		}
		if(strcmp(arg[1],"~")==0)
			chdir(original_path);
		else if (chdir(arg[1]) !=0)
			printf("Error:%s not found.\n",arg[1]);
	}
}
