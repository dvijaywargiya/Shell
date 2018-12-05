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

void command_bg(char ** arg)
{
	if(arg[1] == NULL)
	{
		perror("Enter Job Number");
		return;
	}
	int job;
	job = atoi(arg[1]);
	command_jobs(arg,0);
	pid_t pid;

	if(oj[job-1].pid != 0 && oj[job-1].status == 2)
	{
		pid = oj[job-1].pid;
		printf("%d\n", pid);
		int check=kill(pid, SIGCONT);
		if (check < 0)
		{
	        printf("bg %d: Background-Process not found\n", pid);
	        return;
	    }
	    if(check >= 0)
    		process_names[pid].status=1;
	}else
	{
		perror("Job not found");
	}
}