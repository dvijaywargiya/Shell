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

void details (char *arg)
{
	struct passwd *user[1];
    struct group *group[1];
    struct tm *starttime[1];
    time_t now;
    int year;
    char mod[20];
    struct stat fileStat;   
    if(stat(arg,&fileStat) < 0)
    {
        printf("Exit, file not found.\n");
        return;
    }
    
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf(" ");
    printf("%d ",(int)fileStat.st_nlink);
    user[0] = getpwuid(fileStat.st_uid);
    printf("%s ", user[0]->pw_name);
    group[0]= getgrgid(fileStat.st_gid);
    printf("%s ", group[0]->gr_name);
    printf("\t%d ",(int)fileStat.st_size);

    time(&now);
    year = localtime(&now)->tm_year;
    starttime[0] = localtime(&fileStat.st_ctime);
    if(starttime[0]->tm_year == year)
        strftime(mod,20,"%b %e %R",starttime[0]);
    else
        strftime(mod,20,"%b %e %Y",starttime[0]);
    printf("\t%s ",mod );       
}