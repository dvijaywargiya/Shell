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

int compare (const void * a, const void * b)
{

  const output_jobs *A = a;
  const output_jobs *B = b;

  return ( B->time - A->time);
}


void command_jobs(char ** arg, int flag)
{
	int t=0,i;
	for (i = 0; i < 40000; ++i)
	{
		if(process_names[i].str[0] != '\0')
		{
			// if(process_names[i].status == 1)
			// 	printf("[%d] Running %s[%d]\n",t++,process_names[i].str, i);
			// else
			// 	printf("[%d] Stopped %s[%d]\n",t++,process_names[i].str, i);
			oj[t].status = process_names[i].status;
			strcpy(oj[t].str,process_names[i].str);
			oj[t].pid = i;
			oj[t].time = time(NULL) - process_names[i].init;
			t++;
		}
	}
	qsort (oj, t, sizeof(output_jobs), compare);
	int p=1;
	if (flag==1)
		for(i=0;i<t;i++)
		{
			if(oj[i].status == 1)
				printf("[%d] Running %s[%d]\n",p++,oj[i].str, oj[i].pid);
			else if(oj[i].status == 0)
				printf("[%d] Terminated %s[%d]\n",p++,oj[i].str, oj[i].pid);
			else if(oj[i].status == 2)
				printf("[%d] Stopped %s[%d]\n",p++,oj[i].str, oj[i].pid);
		}
}