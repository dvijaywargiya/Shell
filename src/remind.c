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

void remind(char ** arg)
{
	// printf("%s\n", arg[0]);
	// printf("%s\n", arg[1]);
	// printf("%s\n", arg[2]);
	// printf("%d %d\n", arg[1][0]-48,arg[1][1]-48);
	if(arg[1] == NULL) return;
	int i,j;
	for(i=0;arg[1][i] != '\0';i++)
		continue;
	int t=0;
	int mul = 1;
	//printf("1\n");
	for(j=i-1;j>=0;j--)
	{
		t = t + (arg[1][j]-48)*mul;
		mul*=10;
	}
	char ar[1024];
	strcpy(ar,arg[2]);
	for(j=3;arg[j]!=NULL;j++)
	{	
		strcat(ar," ");
		strcat(ar,arg[j]);
		//printf("%s\n", ar);
	}
	pid_t pid = fork();
	if(pid<0)
	{
	 perror("ERROR");
	}
	else
	if(pid==0)
	{
		sleep(t);
		printf("\nReminder: %s\n", ar);
	}
	//printf("%d\n", time);
	//printf("%ld\n", arr[remindex].creation);
}