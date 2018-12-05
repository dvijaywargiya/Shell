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

void command_overkill(char ** arg)
{
	int i;
	for (i = 0; i < 40000; ++i)
	{
		if(process_names[i].status == 1)
		{
			kill(i,9);
			process_names[i].status=0;
		}
	}
}	