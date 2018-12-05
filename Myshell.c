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
#include "Header.h"

int main()
{

	getcwd(original_path,sizeof(original_path));
	int i,j;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
		while(1)
		{	
			int state;
			pid_t pid;
			while((pid = waitpid(-1,&state,WNOHANG)) > 0)
			{	
				if ((WIFEXITED(state) || WIFSIGNALED(state))&& process_names[pid].str != NULL)
				{
	  				// int es = WEXITSTATUS(state);
	    		// 	if(es==0)
	    		// 		printf("%s with pid %d exited normally.\n",arg[0],wpid);
	    		// 	else
	    		// 		printf("%s with pid %d exited abnormally.\n", arg[0],wpid);
	    		// 	break;
					printf("%s with pid %d exited normally\n",process_names[pid].str,pid);
	    			process_names[pid].status=0;
	    		}
	    	}
			makePrompt();
			char *com =readCommand();
			char ** seprated = seprateSemi(com);
			
			// printf("%s\n", seprated[0]);
			// printf("%s\n", seprated[1]);

			int piping = 0,red=0;
			for(j=0;seprated[j] != NULL;j++)
			{
				char **command = getCommand(seprated[j]);
				//printf("%s\n", command[0]);
				//int check  = checkValidity(command[0]);
			
					//(*builtin_funs[check])(command);
					//printf("2\n");
				piping = checkPiping(command);
				red = checkRedirect(command);
				if(piping || red)
					exec(command);
				else if(command[0] != NULL && strcmp(command[0],"ls")==0)
					command_ls(command);
				else if (command[0] != NULL && strcmp(command[0],"echo")==0)
					command_echo(command);
				else if (command[0] != NULL && strcmp(command[0],"clear")==0)
					command_clear(command);
				else if (command[0] != NULL && strcmp(command[0],"cd")==0)
					command_cd(command);
				else if (command[0] != NULL && strcmp(command[0],"pwd")==0)
					command_pwd(command);
				else if(command[0] != NULL && strcmp(command[0],"remindme")==0)
					remind(command);
				else if(command[0] != NULL && strcmp(command[0],"clock")==0)
					clok(command);
				else if(command[0] != NULL && strcmp(command[0],"pinfo")==0)
					command_pinfo(command);
				else if(command[0] != NULL && strcmp(command[0],"setenv")==0)
					command_setenv(command);
				else if(command[0] != NULL && strcmp(command[0],"unsetenv")==0)
					command_unsetenv(command);
				else if(command[0] != NULL && strcmp(command[0],"jobs")==0)
					command_jobs(command,1);
				else if(command[0] != NULL && strcmp(command[0],"kjob")==0)
					command_kjob(command);
				else if(command[0] != NULL && strcmp(command[0],"bg")==0)
					command_bg(command);
				else if(command[0] != NULL && strcmp(command[0],"fg")==0)
					command_fg(command);
				else if(command[0] != NULL && strcmp(command[0],"quit")==0)
					command_quit(command);
				else if(command[0] != NULL && strcmp(command[0],"overkill")==0)
					command_overkill(command);
				else if(command[0] != NULL)
				{
					exec(command);
					// for(i=0;process_names[i] != NULL; i++)
					// {
					// 	for(j=0;  process_names[i][j] != '\0';j++)
					// 		printf("%c ", process_names[i][j]);
					// 	printf("\n");
					// }
				}else
				perror("ERROR");
				//printf("1\n");
				free(command);
			}
			free(seprated);
			free(com);
		}

		return 0;
}
