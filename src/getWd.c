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

char * getWd()
{
	int i;
	char present[1024];
	char *ret;
	ret = (char*)malloc(sizeof(char)*1024);
	ret[0]='\0';
	getcwd(present,sizeof(present));
	if (strcmp(present,original_path)==0)
	{
		return ret;
	}
	else if(strcmp(present,original_path)>0)
	{
		int k=0;
		for(i=strlen(original_path)+1;i<strlen(present);i++)
			ret[k++]=present[i];
		ret[k]='\0';
		char *rett = (char*)malloc(sizeof(char)*1024);
		strcpy(rett,ret);
		free(ret);
		return rett;
	}
	free(ret);
}