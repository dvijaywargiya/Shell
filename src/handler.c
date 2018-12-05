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

void Handler(int sig)
{
	//printf("%d\n", globalProcessFlag);
	if(globalProcessFlag == 1)
	{
		printf("->Stopped\n");
		// printf("%d\n",globalPid );
		kill(globalPid,SIGTSTP);
		strcpy(process_names[globalPid].str,globalProcessName);
        process_names[globalPid].init = time(NULL);
		process_names[globalPid].status = 2;
		return;
	}
	else
	return;
}