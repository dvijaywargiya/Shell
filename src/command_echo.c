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

void command_echo (char ** arg)
{
	int i;
	if(arg[1] != NULL && strcmp(arg[1],"&")==0)
		arg[1] = NULL;
	for(i=1;arg[i]!=NULL;i++)
	{
		printf("%s ", arg[i]);
	}
	printf("\n");
}