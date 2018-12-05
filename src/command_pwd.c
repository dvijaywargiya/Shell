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

void command_pwd (char ** arg)
{
	if(arg[1] != NULL && strcmp(arg[1],"&")==0)
		arg[1] = NULL;
	char*path = (char*)malloc(sizeof(char)*1024);
	getcwd(path,1024);
	printf("%s\n", path);
	free(path);
}
