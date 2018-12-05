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

int checkBackground(char ** arg)
{
	int i,j;
	for(i=0; arg[i] != NULL; i++)
	{
		if(strcmp(arg[i],"&")==0)
			return i;
	}
	return -1;		
}