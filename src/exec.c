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

int fl;

void handle(int sig)
{
    fl=1;
    kill(globalPid,SIGSTOP);
    strcpy(process_names[globalPid].str,globalProcessName);
    process_names[globalPid].init = time(NULL);
    process_names[globalPid].status = 2;
}

void handle1(int sig)
{
    kill(globalPid,9);
}

void exec(char ** arg)
{
    fl=0;
    globalProcessFlag=0;
	int i,background=checkBackground(arg);
    int red=0,piping=0;
    red=checkRedirect(arg),index;
    piping=checkPiping(arg);

    if(background!=-1 && (strcmp(arg[0],"vim")==0 || strcmp(arg[0],"vi")==0))
        return;

	if(background>=0)
	{
		for(i=background;arg[i] != NULL; i++)
			arg[i] = arg[i+1];
	}
    if(piping && red)
    {
        handlePipesandRedirection(arg);
        return;
    }

    if(piping)
    {
        handlePipes(arg);
        return;
    }

    
    if(red)
    {
        redirect(arg);
        return;
    }

	pid_t pid, wpid;
    int state;

    pid = fork();
    globalPid = pid;
    strcpy(globalProcessName,arg[0]);
    signal(SIGTSTP,handle);

    if(background==-1)
        signal(SIGINT,handle1);

    int flag=0;
    if (pid < 0) {
    	perror("ERROR");
    	flag=1;
    }
    else if(pid==0) 
    {
    	int x = execvp(arg[0], arg);
        if(x < 0)
        {
            perror("ERROR");
        	flag=1;
        }
        exit(0);
    }
    if(background==-1 && fl==0)
    {
        wpid = waitpid(pid, &state, WUNTRACED);
    }
    // printf("%d\n", pid);
    if(background != -1)
    {
        strcpy(process_names[pid].str,arg[0]);
        process_names[pid].status = 1;
        process_names[pid].init = time(NULL);
    }
    // printf("%s\n", process_names[pid].str);
}