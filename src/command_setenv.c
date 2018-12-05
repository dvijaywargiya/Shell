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

void command_setenv (char **arg)
{
	if ((arg[2] == NULL) || (arg[3] != NULL) )
	{
		perror("Number of arguments is incorrect.");
	}
	if (setenv(arg[1],arg[2],1) != 0) 
	{
		perror("shell");
	}
}
