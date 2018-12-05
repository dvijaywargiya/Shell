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

void clok(char ** arg)
{

	if(arg[1] != NULL && strcmp(arg[1],"-t")==0 && arg[2] != NULL && arg[3] != NULL &&strcmp(arg[3],"-n")==0 && arg[4] != NULL)
	{
		int j,k,mul=1,t=0,i,n=0;

		for(j=0;arg[2][j] != '\0';j++);
		for(k=j-1;k>=0;k--)
		{
			t=t+(arg[2][k]-48)*mul;
			mul*=10;
		}
		//printf("%d\n", t);
		mul=1;
		for(j=0;arg[4][j] != '\0';j++);
		for(k=j-1;k>=0;k--)
		{
			n=n+(arg[4][k]-48)*mul;
			mul*=10;
		}
		//printf("%d\n", n);
		time_t init = time(NULL);
		time_t exit = time(NULL);
		time_t brk = time(NULL);
		while(1)
		{	
			exit = time(NULL);
			if(exit - brk == n) break;
			if(exit - init == t)
			{
				init = time(NULL);
				char path[1024];
				strcpy(path,"/proc/driver/rtc");
				FILE *file = fopen(path,"r");		
				char time[10];
				char date[10];
				fscanf(file,"rtc_time		: %s\n",time);
				fscanf(file,"rtc_date		: %s",date);
				char month[10];
				int a,b;
				a=date[5]-48;
				b=date[6]-48;
				if(a==0 && b==1)
					strcpy(month,"January");
				else if(a==0 && b==2)
					strcpy(month,"February");
				else if(a==0 && b==3)
					strcpy(month,"March");
				else if(a==0 && b==4)
					strcpy(month,"April");
				else if(a==0 && b==5)
					strcpy(month,"May");
				else if(a==0 && b==6)
					strcpy(month,"June");
				else if(a==0 && b==7)
					strcpy(month,"July");
				else if(a==0 && b==8)
					strcpy(month,"August");
				else if(a==0 && b==9)
					strcpy(month,"September");
				else if(a==1 && b==0)
					strcpy(month,"October");
				else if(a==1 && b==1)
					strcpy(month,"November");
				else if(a==1 && b==2)
					strcpy(month,"December");

				printf("%c%c %s %c%c%c%c, %s\n",date[8],date[9],month,date[0],date[1],date[2],date[3],time);
			}
		}
	}else
	{
		printf("Enter the command in a proper format.\n");
	}
}