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

void command_kjob(char ** arg)
{
	if(arg[1] == NULL || arg[2] == NULL)
	{
		perror("Error:Incorrect Arguments");
		return;
	}
	int job = atoi(arg[1]);
	int signal = atoi(arg[2]);
	command_jobs(arg,0);
	pid_t pid;
	if(oj[job-1].pid != 0)
	{
		pid = oj[job-1].pid;
		int check = kill(pid,signal);
		if(check<0)
		printf("Kill %d: Process not found\n", pid);
		if(check>=0 && signal == 9)
		process_names[pid].status=0;
		if(check>=0 && (signal == 17 ||signal == 18 ||signal == 19 ||signal == 20 ||signal == 23 ||signal == 24))
		process_names[pid].status=2	;	
	}else
	{
		perror("Job not found");
	}	

	// printf("%d %d\n", pid, signal);
}