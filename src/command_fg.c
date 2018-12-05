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


void command_fg(char ** arg)
{
	if(arg[1] == NULL)
	{
		perror("Error:Incorrect Arguments");
		return;
	}
	int status;
	int job,i,p=1;
	job = atoi(arg[1]);
	command_jobs(arg,0);
	// for(i=0;oj[i].pid!=0;i++)
	// 	{
	// 		if(oj[i].status == 1)
	// 			printf("[%d] Running %s[%d]\n",p++,oj[i].str, oj[i].pid);
	// 		else
	// 			printf("[%d] Stopped %s[%d]\n",p++,oj[i].str, oj[i].pid);
	// 	}
	pid_t pid;
	if(oj[job-1].pid != 0)
	{
		pid = oj[job-1].pid;
		if(oj[job-1].status == 2)
		{
			process_names[pid].status = 1;
			kill(pid,SIGCONT);
		}
		process_names[pid].str[0] = '\0';
		tcsetpgrp(0, pid);
		int state;
		pid_t wpid;
		waitpid(pid,&state,WUNTRACED);
	}else
	{
		perror("Job not found");
	}
	// while((wpid = waitpid(pid,&state,WNOHANG)) > 0)
	// {	
	// 	if (WIFEXITED(state) && process_names[pid].str != NULL)
	// 	{
	// 		printf("%s with pid %d exited normally\n",process_names[pid].str,pid);
	// 		process_names[pid].status=0;
	// 	}
	// }
	signal(SIGTTOU, SIG_IGN);
    tcsetpgrp(0, getpid());
    signal(SIGTTOU, SIG_DFL);
}