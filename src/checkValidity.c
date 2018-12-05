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

int checkValidity(char * comms)
{
	if (comms[0] == '\n')
		return -2;
	int count = 0;
	while(count<6)
	{
		if (strcmp(comms,builtin_commands[count])==0)
			return count;
		count++;
	}

	return -1;
}